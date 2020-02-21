#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#define N 10000000
  
int aBuffer[N];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
  
void* inputDataThread(void* arg) 
{ 
    /*lock accquired*/
	pthread_mutex_lock(&lock); 

  	int iIndex;  
    printf("\n First thread started...\n"); 
  
    for(iIndex = 0; iIndex < N; iIndex++)
	{
		aBuffer[iIndex] = iIndex;
	}
  
    printf("\n First thread finished...\n"); 
  
  	/*lock released*/
    pthread_mutex_unlock(&lock); 
  	
	pthread_exit(NULL);
  	
    return NULL; 
} 
 
void* displayDataThread(void* arg) 
{ 
	/*lock accquired*/
    pthread_mutex_lock(&lock); 

	int iIndex;
  
    printf("\n Second thread started...\n"); 
  
    for(iIndex = 0; iIndex < N; iIndex++)
	{
		printf("%d ", aBuffer[iIndex]);
	}

    printf("\n Second thread finished...\n"); 
  
  	/*lock released*/
    pthread_mutex_unlock(&lock); 
  
  	pthread_eixt(NULL);

    return NULL; 
} 
  
int main(void) 
{  
    int iFirstThreadRes;
	int SecondThreadRes;
	pthread_t firstThread;
	pthread_t secondThread;
  	
	sleep(5);
    
	if(pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    iFirstThreadRes = pthread_create(&firstThread, NULL, &inputDataThread, NULL); 
    if (iFirstThreadRes != 0)
	{
    	printf("\nThread can't be created :[%s]", 
        strerror(iFirstThreadRes)); 
        
    } 

	SecondThreadRes = pthread_create(&secondThread, NULL, &displayDataThread, NULL); 
    if (SecondThreadRes != 0)
	{
    	printf("\nThread can't be created :[%s]", 
        strerror(SecondThreadRes)); 
        
    } 

    pthread_join(firstThread, NULL); 
    pthread_join(secondThread, NULL); 
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 
