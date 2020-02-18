#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#define N 10

/*
	* this method prints the odd numbers
	*
	* @param *arg argument to the function
	*
	* return void *
*/
void* displayOdd(void *arg);

/*
	* this method prints the even numbers
	*
	* @param *arg argument to the function
	*
	* return void *
*/
void* displayEven(void *arg);

int main(void)
{
	pthread_t firstThread;
	pthread_t secondThread;
	int iFirstThreadRes;		// stores the return value of first thread on creation
	int iSecondThreadRes;		// stores the return value of second thread on creation
	int iFirstJoinRes;			// stores the return value of first thread on join
	int iSecondJoinRes;			// stores the return value of first thread on join
	int iEven = 0;
	int iOdd = 1;
	
	/*creating first thread*/
	iFirstThreadRes = pthread_create(&firstThread, NULL, displayOdd, (void *)&iOdd);

	/*validating thread*/
	if(iFirstThreadRes)
	{
		perror("Firtst thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread created successfully \xE2\x9C\x93 \n");

	/*creating second thread*/
	iSecondThreadRes = pthread_create(&secondThread, NULL, displayEven, (void *)&iEven);

	/*validating thread*/
	if(iSecondThreadRes)
	{
		perror("Second thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread created successfully \xE2\x9C\x93 \n");

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

void* displayOdd(void *arg)
{
	int iOdd= *((int *)arg);
	int iIndex;

	for(iIndex = 0; iIndex < N; iIndex++)
	{
		printf("FirstThread: Odd: %d\n", iOdd);
		iOdd += 2;
		sleep(3);
	}
}

void* displayEven(void *arg)
{
	int iEven= *((int *)arg);
	int iIndex;

	for(iIndex = 0; iIndex < N; iIndex++)
	{
		printf("SecondThread: Even: %d\n", iEven);
		iEven += 2;
		sleep(3);
	}
}
