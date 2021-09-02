#include "minitalk.h"

/*
	* kill - send a signal to a process or a group of processes
	** Function: int kill(pid_t pid, int sig);
	*** The only signals we can send are SIGUSR1 or SIGUSR2
	**** SIGUSR1 and SIGUSR2 signals are sent to a process to indicate user-defined conditions.

	CLIENT <-> SERVER SETUP
		##CLIENT
			#4	Execute client: ./client [pid] ["message"]
			#5	EXIT_FAILURE if arguments are not 3 (see #4) 
			#6	Convert the PID to integer

	ASCII TO BINARY CONVERSION
		##CLIENT
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
			#10 After the message a newline character will also be sent.
				The "nline" flag indicates that the program must stop after that.

*/
void send_bits(char *message, int pid)
{
	int i;
	int bit;
	int nline;

	bit = -1;
	i = 0;
	nline = 0;

	while (1)
	{
		bit = -1;
		if (!message[i])
		{
			nline = 1;
			message[i] = '\n';
		}
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				//ft_putchar_fd('1', 1);
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else 
			{
				//ft_putchar_fd('0', 1);
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			usleep(200);
		}
		if (nline)
			break ;
		++i;
	}
}

int main(int argc, char *argv[])
{
	int pid;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid arguments", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_bits(argv[2], pid);
	return (0);
}