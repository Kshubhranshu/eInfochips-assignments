#include "FirstThread.c"
/*
	* this method increments the value of shared atomic
	*
	* @param *arg
	*
	* @return void *
*/
void *incrementFirst(void *arg);

/*
	* this method create a new thread
	*
	* @param void
	*
	* @return void
*/
void createFirstThread(int &iCount);
