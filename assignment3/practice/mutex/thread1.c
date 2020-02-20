#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*thread func*/
void* thread1Fun(void *arg);

void callThread1();

void callThread1()
{
	pthread_t thread1;
	int num;
	int ret;

	ret = pthread_create(&thread1, NULL, thread1Fun, (void *)NULL);
	pthread_join(thread1, NULL);

}

void* thread1Fun(void *arg)
{
	printf("inside thread1\n");
}
