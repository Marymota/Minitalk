/*
	*	The pid_t data type is a signed integer type which is capable of representing
		a process ID.
	**	Function: pid_t getpid (void) 
		The getpid function returns the process ID of the current process.

	! https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_554.html

--------------------------------------------------------------------------------------------------
	
	CLIENT <-> SERVER SETUP
		##SERVER
			#1 Create a pid_t variable to store the 'pid' number;
			#2 Use getpid() to get the process ID;
			#3 Print the PID so that it can be used when running client: ./client [PID] [string]
	BINARY TO ASCII CONVERSION
			#11 The variables used in signal_handler() need to be "static" so that they will preserve
				their value when the new bit (signal) arrives.
				The values are reset after we have completes 8 bits that we will the print.
			#12 Use bitwise operators ^ and | 
				-> Letter: 'a' = ASCII: 097 = Binary: 0110 0001
				-> Hex: 0x80 = Decimal: 128 = Binary: 1111 1111
				Using | (OR) to SIGUSR1 and ^ (exclusive OR) for SIGUSR2
				we can convert the bits into characters again (including unicode characters);
*/
#include "minitalk.h"

void signal_handler(int signum)
{
	static char c = 0xFF;
	static int bit = 0;

	if (signum == SIGUSR1)
	{
		//ft_putchar_fd('1', 1);
		c |= 128 >> bit;
	}
	else if (signum == SIGUSR2)
	{
		//ft_putchar_fd('0', 1);
		c ^= 128 >> bit;
	}
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0xFF;
	}
}

int main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}