#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define N 10

int main()
{
	pid_t processId;
	int iIndex;

	/*creating child process*/
	processId = fork();

	if(-1 == processId)
	{
		perror("fork failed\n");
		exit(EXIT_FAILURE);
	}

	else if(0 == processId)
	{
		/*pause the child process*/
		raise(SIGSTOP);
		
		/*executing child task*/
		printf("executing child process task\n");
		for(iIndex = 0; iIndex < N; iIndex++)
		{
			printf("%d ", (iIndex + 1));
		}
	}
	
	else
	{
		/*waiting for the child to finish*/
		waitpid(processId, NULL, WUNTRACED);

		/*resuming the child process*/
		kill(processId, SIGCONT);
		
		/*executing parent task*/
		printf("executing parent process task\n");
		for(iIndex = 0; iIndex < N; iIndex++)
		{
			printf("%d ", (iIndex + 1));
		}
		printf("\n");
		
	}



}
