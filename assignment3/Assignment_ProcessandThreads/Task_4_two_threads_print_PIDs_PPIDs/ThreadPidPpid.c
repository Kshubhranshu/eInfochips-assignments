#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

/*
	* this method prints the pid and ppid of a thread
	*
	* @param *arg argument to the function
	*
	* return void *
*/
void* threadInformation(void *arg);

int main(void)
{
	pthread_t firstThread;
	pthread_t secondThread;
	int iFirstThreadRes;			// stores the return value of first thread on creation
	int iSecondThreadRes;		// stores the return value of second thread on creation
	int iFirstJoinRes;			// stores the return value of first thread on join
	int iSecondJoinRes;			// stores the return value of first thread on join
	
	/*creating first thread*/
	iFirstThreadRes = pthread_create(&firstThread, NULL, threadInformation, NULL);

	/*validating thread*/
	if(iFirstThreadRes)
	{
		perror("Firtst thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread created successfully \xE2\x9C\x93 \n");

	/*creating second thread*/
	iSecondThreadRes = pthread_create(&secondThread, NULL, threadInformation, NULL);

	/*validating thread*/
	if(iSecondThreadRes)
	{
		perror("Second thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread created successfully \xE2\x9C\x93 \n");

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
}

void* threadInformation(void *arg)
{
	int iThreadId;
	int iParentId;

	/*getting pid and ppid*/
	iThreadId = pthread_self();
	iParentId = getpid();
	
	printf("Parent id(ppid): %d\n", iParentId);
	printf("Thread id(pid): %d\n", iThreadId);
	
	/* terminating calling thread */
	pthread_exit(NULL);
}

