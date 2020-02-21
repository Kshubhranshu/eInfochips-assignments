#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *args)
{
	/*lock accquired*/
	pthread_mutex_lock(&lock); 

	printf("\n Second thread started...\n");
	
	/*increments shared count variable*/
	iCount++;

	printf("\n Second thread finished...\n");
	
	/*lock released*/
    pthread_mutex_unlock(&lock); 
  	
	pthread_exit(NULL);
}

void createSecondThread()
{
	pthread_t secondThread;
	int iRes;
	
	/*initializing mutex*/
	iRes = pthread_mutex_init(&lock, NULL)

	/*validating mutex initialization*/
	if(!(iRes))
	{
		perror("Mutex initialization failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Mutex initialization successfully \xE2\x9C\x93 \n");
	
	/*creating first thread*/
	iRes = pthread_create(&secondThread, NULL, &increment, NULL);

	/*validating thread*/
	if(!(iRes))
	{
		perror("Second thread creation failed!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread created successfully \xE2\x9C\x93 \n");
	
	/*joining second thread to main*/
	iRes = pthread_join(secondThread, NULL);
	
	/*validate join*/
	if(!(iRes))
	{
		perror("Second thread failed to join!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Second thread joined successfully  \xE2\x9C\x93 \n");

	pthread_mutex_destroy(&lock);
}

