#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main(void)
{
	FILE *filePointer;
	char achBuffer[SIZE];
	int iCharRead;

	memset(achBuffer, '\0', sizeof(achBuffer));
	filePointer = popen("uname -a", "r");

	if(filePointer != NULL)
	{
		iCharRead = fread(achBuffer, sizeof(char), SIZE, filePointer);
		if(iCharRead > 0)
		{
			printf("Output was:- \n%s\n", achBuffer);
		}
		pclose(filePointer);
	}
}
