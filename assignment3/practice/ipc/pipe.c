#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFSIZE 10

int main(void)
{
	int iDataProcessed;
	int aFilePipes[2];
	const char achData[] = "hello";
	char achBuffer[BUFFSIZE];

	memset(achBuffer, '\0', sizeof(achBuffer));

	if(pipe(aFilePipes) == 0)
	{
		iDataProcessed = write(aFilePipes[1], achData, strlen(achData));
		printf("wrote %d bytes\n", iDataProcessed);
		iDataProcessed = read(aFilePipes[0], achBuffer, BUFFSIZE);
		printf("read %d bytes: %s\n", iDataProcessed, achBuffer);
	}
}
