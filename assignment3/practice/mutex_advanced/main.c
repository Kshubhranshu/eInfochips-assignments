#include "FirstThread.h"
#include "SecondThread.h"
#include <stdio.h>
#define N 5

int iCount;

int main(void)
{
	int iIndex;

		createFirstThread(iCount);

		createSecondThread(iCount);

	printf("Final count value: %u\n", iCount);
}

