#include "headers/SecondThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>

extern atomic_int iCount;

pthread_mutex_t secondLock = PTHREAD_MUTEX_INITIALIZER;

void *incrementSecond(void *args)
{
	/*lock accquired*/
	pthread_mutex_lock(&secondLock); 

	printf("Second thread started...\n");
	
	/*increments shared count variable*/
	iCount++;
	printf("++[iCount = %d]++\n", iCount);

	printf("Second thread finished...\n");
	
	/*lock released*/
    pthread_mutex_unlock(&secondLock); 
  	
	pthread_exit(NULL);
}

void createSecondThread()
{
	pthread_t secondThread;
	int iRes;
	
	/*initializing mutex*/
	iRes = pthread_mutex_init(&secondLock, NULL);

	/*validating mutex initialization*/
	if((iRes != 0))
	{
		perror("Mutex initialization failed(Second Thread)\n");
		exit(EXIT_FAILURE);
	}
	printf("Mutex initialization successfully(Second Thread) \xE2\x9C\x93 \n");
	
	/*creating first thread*/
	iRes = pthread_create(&secondThread, NULL, &incrementSecond, NULL);

	/*validating thread*/
	if(iRes != 0)
	{
		perror("Second thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread created successfully \xE2\x9C\x93 \n");
	
	/*joining second thread to main*/
	iRes = pthread_join(secondThread, NULL);
	
	/*validate join*/
	if(iRes != 0)
	{
		perror("Second thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread joined successfully  \xE2\x9C\x93 \n\n");

	pthread_mutex_destroy(&secondLock);
}

