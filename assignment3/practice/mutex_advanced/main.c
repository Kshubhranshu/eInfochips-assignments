#include "FirstThread.h"
#include "SecondThread.h"
#include <stdio.h>
#include <stdatomic.h>
#define N 5

atomic_int iCount;

int main(void)
{
	int iIndex;

	for(iIndex = 0; iIndex < N; iIndex++)
	{
		createFirstThread();

		createSecondThread();
	}

	printf("Final count value: %d\n", iCount);
}

