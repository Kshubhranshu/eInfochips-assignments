#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	* copies the first n characters from source to destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return char *
*/
char * strncpy(char *pDestination, const char *pSource, int iN);

/*
	* concate the first n characters from source to destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return char *
*/
char * strncat(char *pDestination, const char *pSource, int iN);

/*
	* compares the first n characters of source and destination
	* 
	* @param pDestination pointer to char 
	*
	* @param pSource pointer to char
	*
	* @return int
*/
int strncat(char *pDestination, const char *pSource, int iN);

char * strncpy(char *pDestination, const char *pSource, int iN)
{
	int iIndex;
		
	for (iIndex = 0; iIndex < n && pSource[iIndex] != '\0'; iIndex++)
	{
		pDestination[iIndex] = pSource[iIndex];
	}

	/*adds null char at the end*/
	for ( ; iIndex < iN; iIndex++)
	{
		
	}

	return pDestination;
}

char * strncat(char *pDestination, const char *pSource, int iN)
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

//you left at strncmp 


