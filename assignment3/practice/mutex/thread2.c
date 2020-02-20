#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*thread func*/
void* thread2Fun(void *arg);

void callThread2();

void callThread2()
{
	pthread_t thread2;
	int num;
	int ret;
	
	ret = pthread_create(&thread2, NULL, thread2Fun, (void *)NULL);
	pthread_join(thread2, NULL);

}

void* thread2Fun(void *arg)
{
	printf("inside thread2\n");
}
