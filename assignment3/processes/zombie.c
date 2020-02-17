/*zombie process*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	/*create a child process*/
	pid = fork();
	if(pid == 0)
	{
		exit(0);
	}
	else 
	{
		sleep(3);
		system("ps -eo pid,comm,status,ppid\n");
	}
	return 0;


}
