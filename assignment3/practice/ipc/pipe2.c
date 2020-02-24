#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFFSIZE 10

int main(void)
{
	int iDataProcessed;
	int aFilePipes[2];
	const char achData[] = "hello";
	char achBuffer[BUFFSIZE];
	pid_t forkResult;

	memset(achBuffer, '\0', sizeof(achBuffer));

	if(pipe(aFilePipes) == 0)
	{
		forkResult = fork();

		if(forkResult == -1)
		{
			perror("Fork failure\n");
			exit(EXIT_FAILURE);
		}
		if(forkResult == 0)
		{
			iDataProcessed = read(aFilePipes[0], achBuffer, BUFFSIZE);
			printf("Read %d bytes: %s\n", iDataProcessed, achBuffer);
		}
		else
		{
			iDataProcessed = write(aFilePipes[1], achData, strlen(achData));
			printf("wrote %d bytes\n", iDataProcessed);
		}
	}
}
