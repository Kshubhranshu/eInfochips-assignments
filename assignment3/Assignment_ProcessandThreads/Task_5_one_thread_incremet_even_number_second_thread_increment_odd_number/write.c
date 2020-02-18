#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>

/*
	* this method shows the file usage
	*
	* @param pFileName stores the file name 
	*
	* @return void
*/
void getFileUsage(const char *pFileName);

/*
	* this method writes into file using first thread
	*
	* @param pFilPointer stores the file address
	*
	* @return void *
*/
void* inputFirstThreadData(void *arg);

/*
	* this method writes into file using second thread
	*
	* @param pFilPointer stores the file address
	*
	* @return void *
*/
void* inputSecondThreadData(void *arg);

int main(void)
{
	char *pFileName = "file.txt";
	FILE *pFilePointer;
	pthread_t firstThread;
	pthread_t secondThread;
	int iFirstThreadRes;
	int iSecondThreadRes;
	int iFirstJoinRes;
	int iSecondJoinRes;
	
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

	iFirstThreadRes = pthread_create(&firstThread, NULL, inputFirstThreadData, (void *)pFilePointer);

	/*validating thread*/
	if(iFirstThreadRes)
	{
		perror("Firtst thread creation failed!!\n");

		/*closing file*/
		fclose(pFilePointer);
		printf("File closed successfully \xE2\x9C\x93\n");
		exit(EXIT_FAILURE);
	}

	/*creating second thread*/
	iSecondThreadRes = pthread_create(&secondThread, NULL, inputSecondThreadData, (void *)pFilePointer);

	/*validating thread*/
	if(iSecondThreadRes)
	{
		perror("Second thread creation failed!!\n");

		/*closing file*/
		fclose(pFilePointer);
		printf("File closed successfully \xE2\x9C\x93\n");
		exit(EXIT_FAILURE);
	}

	/*joining first thread to main*/
	iFirstJoinRes = pthread_join(firstThread, NULL);

	/*validate join*/
	if(iFirstJoinRes)
	{
		perror("First thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread joined successfully  \xE2\x9C\x93 \n");

	/*joining second thread to main*/
	iSecondJoinRes = pthread_join(secondThread, NULL);

	/*validate join*/
	if(iSecondJoinRes)
	{
		perror("Second thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread joined successfully  \xE2\x9C\x93 \n");

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

void* inputFirstThreadData(void *arg)
{
	FILE *pFilePointer = (FILE *)arg;
	char achData[6] = {"ABCD\n"};

	/*writing in file*/
	printf("First thread created successfully \xE2\x9C\x93 \n");
	printf("First thread ready to write data\n");
	fputs(achData, pFilePointer);
	printf("Data written successfully(first thread) \xE2\x9C\x93\n");
}

void* inputSecondThreadData(void *arg)
{
	FILE *pFilePointer = (FILE *)arg;
	char achData[6] = {"abcd\n"};

	/*writing in file*/
	printf("Second thread created successfully \xE2\x9C\x93 \n");
	printf("Second thread ready to write data\n");
	fputs(achData, pFilePointer);
	printf("Data written successfully(second thread) \xE2\x9C\x93\n");
}
