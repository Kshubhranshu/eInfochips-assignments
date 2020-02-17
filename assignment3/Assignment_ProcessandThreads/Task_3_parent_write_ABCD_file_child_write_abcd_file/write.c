#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/*
	* this method shows the file usage
	*
	* @return void
*/
void getFileUsage(const char *pFileName);

int main(void)
{
	char *pFileName = "file.txt";
	FILE *pFilePointer;
	pid_t processId;
	char childData[6] = {"ABCD\n"};
	char parentData[6] = {"abcd\n"};
	
	/*file usage information*/
	getFileUsage(pFileName);

	/*stores the address of the file opened*/
	pFilePointer = fopen(pFileName, "w");

	/*checks whether file exits or not*/
	if(NULL == pFilePointer)
	{
		printf("File doesnot exists!\n");
		exit(ENOENT);
	}

	printf("File opened successfully \xE2\x9C\x93 \n");
	
	/*creating child process*/
	processId = fork();

	if(-1 == processId)
	{
		perror("Fork failed\n");
		exit(ENOMEM);
	}

	else if(0 == processId)
	{
		/*writing in file*/
		printf("Child process ready to write data\n");
		fputs(childData, pFilePointer);
		printf("Data written successfully \xE2\x9C\x93\n");
	}

	else
	{	
		/*preventing zombie process*/
		wait(NULL);

		/*writing in file*/
		printf("Parent process ready to write data\n");
		fputs(parentData, pFilePointer);
		printf("Data written successfully \xE2\x9C\x93\n");
	}

	/*closing file*/
	fclose(pFilePointer);
	printf("File closed successfully \xE2\x9C\x93\n");
}

void getFileUsage(const char *pFileName)
{
	printf("File Usage\n");
	printf("Input file name	: %s\n", pFileName);
	printf("File directory	: \n");
	system("pwd");
	printf("\n");
}


