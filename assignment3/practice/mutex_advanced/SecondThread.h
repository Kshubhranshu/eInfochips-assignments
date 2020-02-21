#include "SecondThread.c"
/*
	* this method increments the value of shared atomic
	*
	* @param *arg
	*
	* @return void *
*/
void *incrementSecond(void *arg);

/*
	* this method create a new thread
	*
	* @param void
	*
	* @return void
*/
void createSecondThread(int &iCount);
