#include "minitalk.h"

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

		##CLIENT
			#4 Execute client: ./client [pid] ["message"]
			#5 EXIT_FAILURE if arguments are not 3 (see #4) 
			#6 Convert the PID to integer
*/


int main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		;
}