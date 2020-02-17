#include <stdio.h>i
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t processId = getpid();
	printf("Parent Process id: %d\n", (int)processId);
	
	/*calling child process*/
	processId = fork();

	if(processId < -1)
	{
		perror("Fork failed to execute\n");
		exit(EXIT_FAILURE);
	}
	
	else if(0 != processId)
	{
		/*preventing zombie process*/
		wait(NULL);
		
		printf("inside parent process\n");
		sleep(5);
		system("ps -eo pid,comm,status,ppid\n");
		printf("Parent process terminates\n");

	}

	else if(0 == processId)
	{
		printf("inside child process\n");
		printf("child process terminates\n");
		exit(0);
	}
}

