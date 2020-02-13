/*
statement: 1. Write versions of the library functions strncpy, strncat and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <errno.h>
#define N 20

enum Operations {CPY = 1, CAT = 2, CMP = 3}; 

/*
	* @id 1.1
	*
	* copies the first n characters from source to destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return char *
*/
char * strNCpy(char *pDestination, const char *pSource, int iN);

/*
	* @id 1.2
	*
	* concate the first n characters from source to destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return char *
*/
char * strNCat(char *pDestination, const char *pSource, int iN);

/*
	* @id 1.3
	*
	* compares the first n characters of source and destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return int
*/
int strNCmp(const char *pString1, const char *pString2, int iN);

int main()
{
	int iN; // no of bytes
	char achSourceBuffer[N];
	char achDestinationBuffer[N];
	int iChoice;
	int iLength = 0;// for comparing two strings
	int iResult; // stores the return value for compare function
	
	/*inputs*/
	printf("Enter data in first buffer(src): ");
	scanf("%s", achSourceBuffer);

	/*validate input*/
	if(strlen(achSourceBuffer) > N - 1)
	{
		printf("Buffer limit exceeded!!\n");
		exit(EOVERFLOW);
	}

	printf("Enter data in second buffer(dest): ");
	scanf("%s", achDestinationBuffer);

	/*validate input*/
	if(strlen(achSourceBuffer) > N - 1)
	{
		printf("Buffer limit exceeded!!\n");
		exit(EOVERFLOW);
	}

	printf("\n");
	printf("[1]Copy Strings\n[2]Concate Strings\n[3]Compare Strings\n[4]Print Buffers\n");
	printf("Select a choice to perform: ");
	scanf("%d", &iChoice);
	printf("\n");


	switch(iChoice)
	{
		case CPY: 	
					/*copy source string to destination string up to n chars*/
					printf("No of characters to copy: ");
					scanf("%d", &iN);

					/*validate N*/
					if((iN > N - 1) || (iN > strlen(achSourceBuffer) + 1))
					{
						printf("Characters limit exceeded!!\n");
						break;
					}	
					strNCpy(achDestinationBuffer, achSourceBuffer, iN);
					printf("Data copied successfully \xE2\x9C\x93\n");
					printf("Destination buffer data: %s\n", achDestinationBuffer);
					break;
		case CAT:
					/*concates two buffers upto n chars*/


		case CMP:
					/*compares two buffers upto n chars*/
					printf("No of characters to compare: ");
					scanf("%d", &iN);

					/*check which buffer length is smaller*/
					iLength = (strlen(achSourceBuffer) > strlen(achDestinationBuffer)) ? strlen(achDestinationBuffer) : strlen(achSourceBuffer); 

					/*validate N*/
					if((iN > N - 1) || iN > iLength)
					{
						printf("Characters limit exceeded!!\n");
						break;
					}

					iResult = strNCmp(achSourceBuffer, achDestinationBuffer, iN);

					if(iResult > 0)
					{
						printf("Destination string > Source string\n");
					}
					else if(iResult < 0)
					{
						printf("Source string > Destination string\n");
					}
					else
					{
						printf("Source string = Destination string\n");
					}

					break;

		default:    
					/*invalid choice*/
					printf("Invalid input\n");
					break;  	
	}
}

char * strNCpy(char *pDestination, const char *pSource, int iN)
{
	int iIndex;
		
	for (iIndex = 0; iIndex < iN && pSource[iIndex] != '\0'; iIndex++)
	{
		pDestination[iIndex] = pSource[iIndex];
	}

	/*adds null char at the end*/
	for ( ; iIndex < iN; iIndex++)
	{
		pDestination[iIndex] = '\0';	
	}

	return pDestination;
}

char * strNCat(char *pDestination, const char *pSource, int iN)
{
	int iIndex;
	int iDestinationLength = strlen(pDestination);
		
	for (iIndex = 0; iIndex < iN && pSource[iIndex] != '\0'; iIndex++)
	{
		pDestination[iIndex + iDestinationLength] = pSource[iIndex];
	}
	pDestination[iIndex + iDestinationLength] = '\0';

	return pDestination;
}

int strNCmp(const char *pString1, const char *pString2, int iN)
{
	while(iN--)
	{
		if(*pString1++ != *pString2++)
		{
			return (*(--pString1) - *(--pString2));
		}
	}
	return 0;
}



