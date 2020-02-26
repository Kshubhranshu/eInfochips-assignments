#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PIPESIZE 2

enum STATUS{ERR = -1, SUCC = 0};

int main(void)
{
	int iRet;
	int aFilePipes[PIPESIZE];
	const char achData[] = "hello 123";
	char achBuffer[BUFSIZ + 1];
	pid_t forkRes;

	/*initializing buffer with null vlaues*/
	memset(achBuffer, '\0', sizeof(achBuffer));

	printf("Inside producer process...\n");

	if(pipe(aFilePipes) == SUCC)
	{
		/*creating child process*/
		forkRes = fork();

		/*validating child process and parent process*/
		if(ERR == forkRes)
		{
			perror("Child process failed to create!!!\n");
			close(aFilePipes)
			exit(EXIT_FAILURE);
		}
		else if(SUCC == forkRes)
		{
			sprintf(achBuffer, "%d", aFilePipes[0]);
			iRet = execl("consumer", "consumer", achBuffer, NULL);
			
			/*validate process execution*/
			if(ERR == iRet)
			{
				perror("Process execution failed!!!\n");
				close(aFilePipes);
				exit(EXIT_FAILURE);
			}
			close(aFilePipes);
			exit(EXIT_SUCCESS);
		}
		else
		{
			write(aFilePipes[1], achData, strlen(achData));
			printf("%d wrote data...\n", getpid());
		}
	}
	else 
	{
		perror("Pipe failed!!!\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
}
