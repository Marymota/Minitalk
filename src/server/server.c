/*
	RESOURCES:
		github.com/mlanca-c/Minitalk
		bing.tistory.com/5
		gnu.org/software/libc/manual/html_node/Signal-Handling.html

	others:
		stack_overflow: "Get PID of the signal sender in C [closed]"

	*	The pid_t data type is a signed integer type which is capable of representing
		a process ID.
	**	Function: pid_t getpid (void) 
		The getpid function returns the process ID of the current process.

	! https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_554.html

--------------------------------------------------------------------------------------------------
	
	CLIENT <-> SERVER SETUP
			#1 Create a pid_t variable to store the 'pid' number;
			#2 Use getpid() to get the process ID;
			#3 Print the PID so that it can be used when running client: ./client [PID] [string]

	BINARY TO ASCII CONVERSION
			#11 The variables used in signal_handler() need to be "static" so that they will preserve
				their value when the new bit (signal) arrives.
				The values are reset after we have completes 8 bits that we will the print.
			#12 Use bitwise operators ^ and | 
				#12.1	Letter: 'a' = ASCII: 097 = Binary: 0110 0001
				#12.2	Hex: 0x80 = Decimal: 128 = Binary: 1111 1111
				#12.3	Using | (OR) to SIGUSR1 and ^ (exclusive OR) for SIGUSR2
				#12.4	we can convert the bits into characters again (including unicode characters);

	CREATE MESSAGE 
			#14 When 8 bits have been recieved if 'c' is a character it is added to the "message" string
				#14.1	We allocate memory for a two characters string: 
						the one recieved and the null character
				#14.2	If we already have characters allocated we need to copy that string and give it 
						two more characters for 'c' and 'null'
			#15 When 'c' is not a character and 8 bits have been recieved the message string is printed;
		*	printf() is not signal safe; Don't use it inside a signal handler.
		**	
		***	We keep the signal_handler() variables as static since we need to update them and keep track
			of its values everytime we recieve a new signal
		****	Changed from signal() to sigaction() to be able to easely get the client PID
			->	The siginfo_t contains a variety of data including "si_pid": Process ID of sending process;
				that we can use to send signals to the client to confirm reception (Bonus)
*/
#include "minitalk.h"

char	*print_string(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	free(message);
	return (NULL);
}

void	send_signal(int pid, int signum)
{			
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	if (++bit == 8)
	{
		if (!c)
		{
			message = print_string(message);
			send_signal(pid, SIGUSR2);
		}
		else
			message = ft_str_add_char(message, c);
		bit = 0;
		c = 0xFF;
	}
	send_signal(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
