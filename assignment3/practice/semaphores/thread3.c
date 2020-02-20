#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#define SIZE 1024

void *threadFunction(void *arg);

sem_t binSem;

char achBuffer[SIZE];

int main()
{
	int iRes;
	pthread_t thread;
	void *threadResult;

	iRes = sem_init(&binSem, 0, 0);
	if(iRes != 0)
	{
		perror("Semaphore initialization failed\n");
		exit(EXIT_FAILURE);
	}

	iRes = pthread_create(&thread, NULL, threadFunction, NULL);
	if(iRes != 0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Input some text. Enter 'end' to finish...\n");
	while(strncmp("end", achBuffer, 3) != 0)
	{
		fgets(achBuffer, SIZE, stdin);
		sem_post(&binSem);
	}

	printf("\nwaiting for thread to finish...\n");
	iRes = pthread_join(thread, NULL);
	if(iRes != 0)
	{
		perror("Thread join failed!\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	sem_destroy(&binSem);
}

void *threadFunction(void *arg)
{
	sem_wait(&binSem);
	while(strncmp("end", achBuffer, 3) != 0)
	{
		printf("You input %ld characters\n", strlen(achBuffer) - 1);
		sem_wait(&binSem);
	}
	pthread_exit(NULL);
}
