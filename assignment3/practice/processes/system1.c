#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("running ps with system\n");
	system("ps\n\n");
	printf("done\n");
	printf("listing files in dir\n");
	system("ls -la");
	system("gedit zombie.c");

	printf("exec\n");
	//execlp("ls", "ls", "-la", NULL);
	execlp("ps", "ps", "ax", NULL);


}
