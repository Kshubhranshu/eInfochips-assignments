#include "shm_com.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>

int main()
{
	char *str;
	int shmid;

	shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

	if(shmid == -1)
	{
		perror("shmget failed\n");
		exit(EXIT_FAILURE);
	}
	str = (char *)shmat(shmid, NULL, 0);
	if(shared_memory == (void *)-1)
	{
		perror("shmat failed\n");
		exit(EXIT_FAILURE);
	}

	printf("memory attached at %lu\n", (unsigned long)str);

	printf("length of : %s\n", str);
		

	if(shmdt(str) == -1)
	{
		perror("shmdt failed\n");
		exit(EXIT_FAILURE);
	}

 	shmctl(shmid, IPC_RMID, NULL);	
}
