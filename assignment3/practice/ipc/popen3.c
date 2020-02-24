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
	filePointer = popen("ls -la", "r");
	if(filePointer != NULL)
	{
		iCharRead = fread(achBuffer, sizeof(char), SIZE, filePointer);
		while(iCharRead > 0)
		{
			achBuffer[iCharRead - 1] = '\0';
			printf("Reading %d:- \n %s \n", SIZE, achBuffer);
			iCharRead = fread(achBuffer, sizeof(char), SIZE, filePointer);
		}
		pclose(filePointer);
	}
}
