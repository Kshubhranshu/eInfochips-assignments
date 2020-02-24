#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main(void)
{
	FILE *filePointer;
	char achBuffer[SIZE];

	memset(achBuffer, '\0', sizeof(achBuffer));
	sprintf(achBuffer, "Once upon a time, in Jungle...\n");
	filePointer = popen("od -c", "w");

	if(filePointer != NULL)
	{
		fwrite(achBuffer, sizeof(char), strlen(achBuffer), filePointer);
		pclose(filePointer);
	}
}

