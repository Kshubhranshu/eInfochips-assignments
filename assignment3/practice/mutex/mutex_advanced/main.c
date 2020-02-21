#include "FirstThread.c"
#include "SecondThread.c"
#include <stdio.h>
#include <stdatomic.h>
#define N 5

atomic_int iCount;

int main(void)
{
		for(int i = 0; i < 3; i++)
		{
		/*creating first thread*/
		createFirstThread();

		/*creating second thread*/
		createSecondThread();
		}
		
	printf("Final iCount value = %d\n", iCount);
}

