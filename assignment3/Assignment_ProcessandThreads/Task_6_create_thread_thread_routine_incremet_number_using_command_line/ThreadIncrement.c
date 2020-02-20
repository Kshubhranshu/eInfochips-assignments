#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>
#include <sched.h>
#define INFINITE 1

pthread_t thread;		// thread variable	
int iThreadJoinRes;		// stores the return value of first thread on join

/*
	* this method increments the number
	*
	* @param *arg argument to the function
	*
	* return void *
*/
void* increment(void *arg);

/*
	* this method is signal handler for SIGINT
	*
	* @param iSigNum is the signal number of the interrupt
	*
	* @return void
*/
void sigintHandler(int iSigNum);

int main(void)
{
	int iThreadRes;				// stores the return value of first thread on creation
	int iThreadJoinRes;			// stores the return value of first thread on join
	int iNumber;
	pthread_attr_t tattr;
	int iReturn;
	int iNewPrio = -20;
	struct sched_param param;

	/*input value*/
	printf("Enter number: ");
	scanf("%d", &iNumber);

	/*disabling ctrl+c interrupt*/ 
	signal(SIGINT, sigintHandler);

	while(INFINITE)
	{
		/*setting thread priority*/

		/* initialized with default attributes */
		iReturn = pthread_attr_init (&tattr);
		
		/*validate attribute creation*/
		if (!iReturn)
		{
			perror("Attribute creation failed\n");
			exit(EXIT_FAILURE);
		}
		printf("Attribute creation successfull  \xE2\x9C\x93 \n");

		/* safe to get existing scheduling param */
		iReturn = pthread_attr_getschedparam (&tattr, &param);

		/* set the priority; others are unchanged */
		param.sched_priority = iNewPrio;

		/* setting the new scheduling param */
		iReturn = pthread_attr_setschedparam (&tattr, &param); 

		/*validate scheduling priority creation*/
		if (!iReturn)
		{
			perror("Setting scheduling priority failed\n");
			exit(EXIT_FAILURE);
		}
		printf("Setting scheduling priority successfull  \xE2\x9C\x93 \n");
		
		/*increment number via main*/
		iNumber++;
		printf("main: number incremented  : %d\n\n", iNumber);

		sleep(4);
		
		/*creating thread*/
		iThreadRes = pthread_create(&thread, NULL, increment, (void *)&iNumber);
		
		/*validating thread*/
		if(iThreadRes)
		{
			perror("Thread creation failed!!\n");
			exit(EXIT_FAILURE);
		}

		/*joining thread to main*/
		iThreadJoinRes = pthread_join(thread, NULL);
	
		/*validate join*/
		if(iThreadJoinRes)
		{
			perror("Thread failed to join!!\n");
			exit(EXIT_FAILURE);
		}
		printf("Thread joined successfully  \xE2\x9C\x93 \n\n");
		
		sleep(3);
	}
}

void sigintHandler(int iSigNum)
{
    signal(SIGINT, sigintHandler);

	printf("Program exited successfully \xE2\x9C\x93 \n");
    exit(EXIT_SUCCESS);
}

void* increment(void *arg)
{	
	sleep(4);
	printf("Thread created successfully \xE2\x9C\x93 \n");
	int iNumber = ++(*((int *)arg));
	printf("thread: number incremented: %d\n", iNumber);

	/* terminating calling thread */
	pthread_exit(NULL);
}


