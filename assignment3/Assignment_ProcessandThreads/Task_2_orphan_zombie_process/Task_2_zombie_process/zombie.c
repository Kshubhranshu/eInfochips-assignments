#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	pid_t processId = getpid();
	printf("Parent Process id: %d\n", (int)processId);
	
	/*calling child process*/
	processId = fork();

	if(processId < -1)
	{
		perror("Fork failed to execute\n");
		exit(ENOMEM);
	}
	
	else if(0 != processId)
	{
		/*preventing zombie process*/
		wait(NULL);
		
		printf("inside parent process\n");
		sleep(50);
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

