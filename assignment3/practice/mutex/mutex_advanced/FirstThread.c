#include "headers/FirstThread.h"
#include "headers/FirstThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>

extern atomic_int iCount;

extern irstLock = PTHREAD_MUTEX_INITIALIZER;

void *incrementFirst(void *args)
{
	/*lock accquired*/
	pthread_mutex_lock(&lock); 

	printf("First thread started...\n");
	
	/*increments shared count variable*/
	iCount++;
	printf("++[iCount = %d]++\n", iCount);

	printf("First thread finished...\n");
	
	/*lock released*/
    pthread_mutex_unlock(&lock); 
  	
	pthread_exit(NULL);
}

void createFirstThread()
{
	pthread_t firstThread;
	int iRes;
	
	/*initializing mutex*/
	iRes = pthread_mutex_init(&lock, NULL);

	/*validating mutex initialization*/
	if(iRes != 0)
	{
		perror("Mutex initialization failed(First Thread)\n");
		exit(EXIT_FAILURE);
	}
	printf("Mutex initialization successfully(First Thread) \xE2\x9C\x93 \n");

	/*creating first thread*/
	iRes = pthread_create(&firstThread, NULL, &incrementFirst, NULL);

	/*validating thread*/
	if(iRes != 0)
	{
		perror("First thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread created successfully \xE2\x9C\x93 \n");
	
	/*joining first thread to main*/
	iRes = pthread_join(firstThread, NULL);
	
	/*validate join*/
	if(iRes != 0)
	{
		perror("First thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread joined successfully  \xE2\x9C\x93 \n\n");

	pthread_mutex_destroy(&lock);
}

