#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

int num = 0;

void *fun1(void *);
void *fun2(void *);

int main(void)
{
	pthread_t thread1;	
	pthread_t thread2;
	
	sem_init(&sem, 0, 1);

	pthread_create(&thread1, NULL, fun1, (void *)&num);
	pthread_create(&thread2, NULL, fun2, (void *)&num);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&sem);
}

void *fun1(void * arg)
{
	//sem_wait(&sem);
	for(int i = 0; i < 1000; i++)
	{
	printf("num incrented by thread 1 : %d\n", ++(num));
	}
	//sem_post(&sem);
	pthread_exit(NULL);
}

void *fun2(void * arg)
{
	//sem_wait(&sem);
	for(int i = 0; i < 1000; i++)
	{
	printf("num decremented by thread 2 : %d\n", --(num));
	}
	//sem_post(&sem);
	pthread_exit(NULL);
}
