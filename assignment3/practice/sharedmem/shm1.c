#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include "shm_com.h"

int main(void)
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
	if(str == (void*)-1)
	{
		perror("shmat failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Memory attached at %lu\n", (unsigned long)str);

	scanf("%s", str);
	
	shmdt(str);
}
