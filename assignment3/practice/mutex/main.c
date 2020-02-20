#include <stdio.h>
#include "thread1.c"
#include "thread2.c"

int main()
{
	callThread1();
	callThread2();
}

