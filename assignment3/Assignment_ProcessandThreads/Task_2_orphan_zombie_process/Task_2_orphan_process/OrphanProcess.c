#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

enum STATUS {ERR = -1, CHILD = 0};

int main()
{
	pid_t processId;

	printf("parent id: %d\n", (int)getpid());
	
	processId = fork();

	if(ERR == processId)
	{
		perror("fork failed to create child\n");
		exit(ENOMEM);
	}

	else if(CHILD == processId)
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
