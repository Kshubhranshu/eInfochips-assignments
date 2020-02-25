#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int iRet;
	char achBuffer[BUFSIZ + 1];
	int iFileDesc;

	printf("Inside consumer process...\n");
	
	/*initializing buffer with null value*/
	memset(achBuffer, '\0', sizeof(achBuffer));

	sscanf(argv[1], "%d", &iFileDesc);
	read(iFileDesc, achBuffer, BUFSIZ);
	printf("%d read data...\n", getpid());
	exit(EXIT_SUCCESS);
}
