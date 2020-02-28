#include <sys/sem.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_SIZ 2

int count = 0;
sem_t sem_id;
pthread_t thread[THREAD_SIZ];

void *threadFunction1(void *arg);

void *threadFunction2(void *arg);

int initsem(key_t key, int nsems);

int sem_create(key_t key);

int sem_init(sem_t *semid, int pshared, unsigned int value);

int sem_initialize(sem_t *semid, int value);

int sem_destroy(sem_t *semid);

int sem_wait(sem_t *semid);

int sem_trywait(sem_t *semid);

int sem_post(sem_t *semid);

int main(void)
{

	sem_init(&sem_id, 0, 1);
	
	for(int i = 0; i < 1000; i++)
	{
	pthread_create(&thread[0], NULL, &threadFunction1, NULL);
	pthread_create(&thread[1], NULL, &threadFunction2, NULL);
	
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	}
	sem_destroy(&sem_id);
}

void *threadFunction1(void *arg)
{
	int ret;

	ret = sem_trywait(&sem_id);
	if(ret == 0)
	{
		printf("Thread 1 locked...\n");
		count++;
		printf("count value(thread 1): %d\n", count);
		pthread_exit(NULL);
		sem_post(&sem_id);
		printf("Thread 1 lock realeased...\n");
	}
	return NULL;
}

void *threadFunction2(void *arg)
{
	int ret;

	ret = sem_wait(&sem_id);
	if(ret == 0)
	{
		printf("Thread 2 locked...\n");
		count--;
		printf("count value(thread 1): %d\n", count);
		pthread_exit(NULL);
		sem_post(&sem_id);
		printf("Thread 1 lock realeased...\n");
	}
	return NULL;
}

int initsem(key_t key, int nsems)
{
	int semid;

	semid = semget(key, nsems, IPC_CREAT | IPC_EXCL | 0666);
	if(semid == -1)
	{
		perror("Semaphore identifier failed!!!\n");
		return -1;
	}
	return semid;
}

int sem_initialize(sem_t *semid, int value)
{
	int ret;

	ret = semctl(*((int *)semid), 0, SETVAL, value);
	if(ret == -1)
	{
		perror("Failed to initialize control!!!\n");
		return ret;
	}
	return ret;
}

int sem_init(sem_t *sem, int pshared, unsigned int value)
{
	int ret = -1;
	key_t key = 6554;
	
	if(value > 1)
	{
		perror("Semaphore value limit exceeded!\n");
		return ret;
		exit(EXIT_FAILURE);
	}

	if(((*((int *)sem)) = initsem(key,1)) == -1)
	{
       return -1;
	   exit(EXIT_FAILURE);
  	}

	ret = sem_initialize(sem, value);
	if(ret == -1)
	{
		perror("Semaphore initialization failed\n");
		return ret;
		exit(EXIT_FAILURE);
	}
	return ret;
}

int sem_destroy(sem_t *semid)
{
	int ret;

	ret = semctl(*((int *)semid), 0, IPC_RMID);
	if(ret == -1)
	{
		perror("Semphore failed to destroy!\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

int sem_wait(sem_t *semid)
{
	int ret;
	struct sembuf sb;
	
	sb.sem_num = 0;
	sb.sem_op = -1;
	sb.sem_flg = 0;

	ret = semop(*((int *)semid), &sb, 1);
	if(ret == -1)
	{
		perror("Semaphore try wait failed!n\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

int sem_trywait(sem_t *semid)
{
	int ret;
	struct sembuf sb;
	
	sb.sem_num = 0;
	sb.sem_op = -1;
	sb.sem_flg = IPC_NOWAIT;

	ret = semop(*((int *)semid), &sb, 1);
	if(ret == -1)
	{
		perror("Semaphore try wait failed!n\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

int sem_post(sem_t *semid)
{
	int ret;
	struct sembuf sb;
	
	sb.sem_num = 0;
	sb.sem_op = 1;
	sb.sem_flg = 0;

	ret = semop(*((int*)semid), &sb, 1);
	if(ret == -1)
	{
		perror("Semaphore try wait failed!n\n");
		sem_destroy(&sem_id);
		return ret;
	}
	return ret;
}
