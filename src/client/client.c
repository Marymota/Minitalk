/*
	* kill - send a signal to a process or a group of processes
	** Function: int kill(pid_t pid, int sig);
	*** The only signals we can send are SIGUSR1 or SIGUSR2
	**** SIGUSR1 and SIGUSR2 signals are sent to a process to indicate user-defined conditions.

	CLIENT <-> SERVER SETUP
			#4	Execute client: ./client [pid] ["message"]
			#5	EXIT_FAILURE if arguments are not 3 (see #4) 
			#6	Convert the PID to integer

	ASCII TO BINARY CONVERSION
			#7	Iterate through the message one character at a time
				For each character is necessary to send 8 bits (1s and 0s)
				SIGURS1 will send 1's and SIGUSR2 will send 0's

				-> Letter: 'a' = ASCII: 097 = Binary: 0110 0001
				-> Hex: 0x80 = Decimal: 128 = Binary: 1000 0000
				-> 1000 0000 >> bit(0) = 1000 0000;
				-> 1000 0000 >> bit(1) = 0100 0000;
				-> 1000 0000 >> bit(2) = 0010 0000; ...
				-> 1 & 1 = 1; 1 & 0 = 0; 
			#8	Use kill() to send the corresponding signal to the 
				to the server by using its process ID.
			#9 	Use usleep() to suspend execution for microseconds intervals
				so that signals are not lost.
			#10 When message[i] has no character in it the program is stopped
	SIGNAL AND MESSAGE CONFIRMATION (BONUS)
			#13 When client recieves a SIGUSR1 signal sends "message sent"
				#13.1	The "flag" in signal_handler blocks other signal
						confirmations after the first;
						Since the server send a confirmation signal every time
						it recieves a signal...
			#16 When client recieves a SIGUSR2 signal send "Message recieved"
				#16.1	The "message recieved" confirmation (SIGUSR2 sent by the
						server)is sent after the message is print by the server;
*/
#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	flag = 1;

	if (signum == SIGUSR1 && flag)
	{
		ft_putstr_fd("\nMessage sent ", 1);
		flag = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("-> Message recieved \n", 1);
		flag = 1;
		exit(EXIT_SUCCESS);
	}
}

void	send_bits(char *message, int pid)
{
	int	i;
	int	bit;

	bit = -1;
	i = 0;
	if (!message)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(100);
		}
		if (!message[i])
			break ;
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || !ft_str_isalnum(argv[1]))
	{
		ft_putstr_fd("Invalid Arguments!\n", 1);
		ft_putstr_fd("./client [PID] [STR]\n", 1);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = ft_atoi(argv[1]);
	send_bits(argv[2], pid);
}
