#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 1000

void *threadFunction(void *arg);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char achBuffer[SIZE];
int iTimeToExit = 0;

int main(void)
{
	int iRes;
	pthread_t thread;

	if(iRes != 0)
	{
		perror("Mutex initialization failed\n");
		exit(EXIT_FAILURE);
	}
	
	iRes = pthread_create(&thread, NULL, threadFunction, NULL);
	if(iRes != 0)
	{
		perror("Thread creation failed\n");
	}

	pthread_mutex_lock(&mutex);
	printf("Input some text. Enter 'end' to finish\n");
	while(!iTimeToExit)
	{
		fgets(achBuffer, SIZE, stdin);
		pthread_mutex_unlock(&mutex);
		
		while(1)
		{
			pthread_mutex_lock(&mutex);
			if(achBuffer[0] != '\0')
			{
				pthread_mutex_unlock(&mutex);
				sleep(1);
			}
			else
			{
				break;
			}
		}
	}
	pthread_mutex_unlock(&mutex);
	
	printf("\nWaiting for thread to finish...\n");
	iRes = pthread_join(thread, NULL);
	if(iRes != 0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");

	pthread_mutex_destroy(&mutex);
	exit(EXIT_SUCCESS);
}

void *threadFunction(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&mutex);
	while(strncmp("end", achBuffer, 3))
	{
		printf("you input %ld characters\n", strlen(achBuffer) - 1);
		achBuffer[0] = '\0';
		pthread_mutex_unlock(&mutex);
		sleep(1);
		pthread_mutex_lock(&mutex);
		
		while(achBuffer[0] == '\0')
		{
			pthread_mutex_unlock(&mutex);
			sleep(1);
			pthread_mutex_lock(&mutex);
		}
	}

	iTimeToExit = 1;
	achBuffer[0] = '\0';
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}
