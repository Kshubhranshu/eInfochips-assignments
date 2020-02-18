#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*thread func*/
void* threadRunner(void *arg);

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	char *msg1 = "first thread\n";
	char *msg2 = "second thread\n";
	int ret1;
	int ret2;
	
	ret1 = pthread_create(&thread1, NULL, threadRunner, (void *)msg1);
	ret2 = pthread_create(&thread2, NULL, threadRunner, (void *)msg2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("first thread ret1 = %d\n", ret1);
	printf("second thread ret2 = %d\n", ret2);
}


void* threadRunner(void *arg)
{
	char *msg;
	msg = (char *)arg;

	int i;
	int threadId;
	
	printf("parent id: %d\n", getpid());
	threadId = pthread_self();
	printf("id : %d\n", threadId);

	for(i = 0; i < 10; i++)
	{
		printf("%s %d\n", msg, i);
		sleep(1);
	}
	return NULL;
}
