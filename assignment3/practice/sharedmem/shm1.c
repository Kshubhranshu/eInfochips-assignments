#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include "shm_com.h"

int main(void)
{
	int running = 1;
	void *shared_memory = NULL;
	struct shared_use_st *shared_stuff;
	int shmid;
	
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);

	if(shmid == -1)
	{
		perror("shmget failed\n")
		exit(EXIT_FAILURE);
	}

	shared_memory = shmat(shmid, NULL, 0);
	if(shared_memory == (void*)-1)
	{
		perror("shmat failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Memory attached at %x\n, (int)shared_memory");

	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff -> written_by_you = 0;
	while(running)
	{
		
	}
}
