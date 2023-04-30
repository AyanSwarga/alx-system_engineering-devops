#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

int main(void)
{
	pid_t pid;

	for (int i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			exit(0); /*child process exits immediately*/
		} else if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
		} else
		{
			perror("fork");
		exit(1);
		}
	}

	infinite_while(); /* parent process enters infinite loop*/

	return (0);
}

