#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h> 
#include "semun.h"
#include <pthread.h>

#define THREAD_SIZ 2

enum STATUS{ERR = -1, ZER = 0};

static int semId;

int iCount;

int setSemValue(void);

void delSemValue(void);

int semaphoreLock(void);

int semaphoreUnlock(void);

void createThread(void);

void *thread0Function(void *arg);

void *thread1Function(void *arg);

int main(void)
{
	int iRet;
	key_t key = 8080;
	int iIndex;

	sem_init((sem_t *)&semId, 0, 1);

	/*getting semaphore identifier id*/
	semId = semget(key, 1, 0666 | IPC_CREAT);
	if(ERR == semId)
	{
		perror("Semaphore failed to obtain identifier!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("Semaphore identifier obtained successfull \xE2\x9C\x93 \n");
	
	/*initializing semaphore*/
	iRet = setSemValue();
	if(ERR == iRet)
	{
		printf("Failed to initialize semaphore!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("Semaphore initialization successfull \xE2\x9C\x93 \n\n");
	
	/*creating threads*/
	createThread();
	
	/*deleting semaphore*/
	delSemValue();
}

int setSemValue(void)
{
	union semun semUnion;

	semUnion.val = 1;
	if(ERR == semctl(semId, 0, SETVAL, semUnion))
	{
		return 0;
	}
	return 1;
}

void delSemValue(void)
{
	union semun semUnion;

	if(ERR == semctl(semId, 0, IPC_RMID, semUnion))
	{
		perror("Failed to delete semaphore!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("Semaphore deletion successfull \xE2\x9C\x93 \n\n");
}

int semaphoreLock(void) 
{
	struct sembuf semBuffer;

	semBuffer.sem_num = 0;
	semBuffer.sem_op = -1;	// locking
	semBuffer.sem_flg = 0;

	if(ERR == semop(semId, &semBuffer, 1))
	{
		perror("Semaphore locking failed!\n");
		return 0;
	}
	return 1;
}

int semaphoreUnlock(void)
{
	struct sembuf semBuffer;

	semBuffer.sem_num = 0;
	semBuffer.sem_op = 1; 	// unlocking
	semBuffer.sem_flg = 0;
	if(ERR == semop(semId, &semBuffer, 1))
	{
		printf("Semaphore unlocking failed!\n");
		return 0;
	}
	return 1;
}

void createThread()
{
	pthread_t thread[THREAD_SIZ];
	int iRet;

	/*creating first thread*/
	iRet = pthread_create(&thread[0], NULL, &thread0Function, NULL);

	/*validating thread*/
	if(ZER != iRet)
	{
		perror("First thread creation failed!!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("First thread created successfully \xE2\x9C\x93 \n");

	/*creating second thread*/
	iRet = pthread_create(&thread[1], NULL, &thread1Function, NULL);

	/*validating thread*/
	if(ZER != iRet)
	{
		perror("Second thread creation failed!!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("Second thread created successfully \xE2\x9C\x93 \n\n");
	
	/*joining first thread to main*/
	iRet = pthread_join(thread[0], NULL);
	
	/*validate join*/
	if(iRet != 0)
	{
		perror("First thread failed to join!!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("First thread joined successfully \xE2\x9C\x93 \n");

	/*joining second thread to main*/
	iRet = pthread_join(thread[1], NULL);
	
	/*validate join*/
	if(iRet != 0)
	{
		perror("Second thread failed to join!!\n");
		delSemValue();
		exit(EXIT_FAILURE);
	}
	printf("Second thread joined successfully \xE2\x9C\x93 \n\n");
}

void *thread0Function(void *arg)
{
	/*locking*/
	if(ZER == semaphoreLock()) exit(EXIT_FAILURE);

	/*critical section*/
	iCount++;
	printf("i am thread[0]: iCount incremented: %d\n", iCount);
	
	/*unlocking*/
	if(ZER == semaphoreUnlock()) exit(EXIT_FAILURE);
}

void *thread1Function(void *arg)
{
	/*locking*/
	if(ZER == semaphoreLock()) exit(EXIT_FAILURE);

	/*critical section*/
	iCount--;
	printf("i am thread[1]: iCount decremented: %d\n", iCount);
	
	/*unlocking*/
	if(ZER == semaphoreUnlock()) exit(EXIT_FAILURE);
}
