#include "FirstThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *args)
{
	/*lock accquired*/
	pthread_mutex_lock(&lock); 

	printf("\n First thread started...\n");
	
	/*increments shared count variable*/
	iCount++;

	printf("\n First thread finished...\n");
	
	/*lock released*/
    pthread_mutex_unlock(&lock); 
  	
	pthread_exit(NULL);
}

void createFirstThread()
{
	pthread_t firstThread;
	int iRes;
	
	/*initializing mutex*/
	iRes = pthread_mutex_init(&lock, NULL)

	/*validating mutex initialization*/
	if(iRes != 0)
	{
		perror("Mutex initialization failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Mutex initialization successfully \xE2\x9C\x93 \n");

	/*creating first thread*/
	iRes = pthread_create(&firstThread, NULL, &increment, NULL);

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
	if(!(iRes))
	{
		perror("First thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("First thread joined successfully  \xE2\x9C\x93 \n");

	pthread_mutex_destroy(&lock);
}

