#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>
#include <sched.h>
#define INFINITE 1

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
	pthread_t thread;
	int iThreadRes;				// stores the return value of first thread on creation
	int iThreadJoinRes;			// stores the return value of first thread on join
	int iNumber;

	printf("Enter number: ");
	scanf("%d", &iNumber);

	/*disabling ctrl+c interrupt*/ 
	signal(SIGINT, sigintHandler);

	while(INFINITE)
	{
		/*priortizing thread*/
		
		/*increment number via main*/
		iNumber++;
		printf("main: number incremented  : %d\n", iNumber);

		sleep(4);
		
		/*creating thread*/
		iThreadRes = pthread_create(&thread, &attr, increment, (void *)&iNumber);
		
		/*validating thread*/
		if(iThreadRes)
		{
			perror("Thread creation failed!!\n");
			exit(EXIT_FAILURE);
		}
		
		sleep(2);
	}
}

void sigintHandler(int iSigNum)
{
    signal(SIGINT, sigintHandler);

//------------
// 	/*joining thread to main*/
//	iFirstJoinRes = pthread_join(firstThread, NULL);
//	
//	/*validate join*/
//	if(iFirstJoinRes)
//	{
//		perror("Thread failed to join!!\n");
//		exit(EXIT_FAILURE);
//	}
//	printf("Thread joined successfully  \xE2\x9C\x93 \n");
//--------------

	printf("Program exited successfully \xE2\x9C\x93 \n");
    exit(EXIT_SUCCESS);
}

void* increment(void *arg)
{	
	sleep(4);

	int iNumber = ++(*((int *)arg));
	printf("thread: number incremented: %d\n", iNumber);
}


