#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/sem.h>

#include "semun.h"

static int set_semvalue(void);
static void del_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);

static int sem_id;

int main(void)
{
	int i;
	int pause_time;
	char op_char = '0';

	srand((unsigned int)getpid());

	sem_id = semget((key_t)1234, 1, 0);
}
