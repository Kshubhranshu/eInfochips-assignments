#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int n;

	char *message;

	printf("starting fork process\n");
	pid = fork();
	switch(pid)
	{
		case -1:
					perror("fork failed");
					exit(1);
	 	case 0: 
					message = "this is child";
					n = 5;
					break;
		defalut: 
					message = "this is parent";
					n = 3;
					break;
	}
	/*
	while(n > 0)
	{
		printf("%s\n", message);
		n--;
		sleep(1);
	}
	*/
	for(; n > 0; n--) 
	{
		puts(message);
		sleep(1);
	}
	exit(0);


}
