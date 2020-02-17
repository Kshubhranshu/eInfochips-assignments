#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t processId;

	printf("parent id: %d\n", (int)getpid());
	
	processId = fork();

	if(-1 == processId)
	{
		perror("fork failed to create child\n");
		exit(ENOMEM);
	}

	else if(0 == processId)
	{
		printf("inside child process\n");
		sleep(500);
	}

	else
	{
		printf("inside parent process\n");
		printf("parent process terminated\n");
		exit(EXIT_SUCCESS);
	}
}
