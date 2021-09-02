#include "minitalk.h"

/*
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

int main(int argc, char *argv[])
{
	pid_t pid;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid arguments", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	return (pid);
}