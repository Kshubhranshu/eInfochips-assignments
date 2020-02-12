/*
1. Write versions of the library functions strncpy, strncat and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
*/

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
int strncmp(const char *pString1, const char *pString2, int iN);

/*****************************************************************************************************************************/

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
		pDestination[iIndex] = '\0';	
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

int strncmp(const char *pString1, const char *pString2, int iN)
{
	while(iN--)
	{
		if(*pString1++ != *pString2++)
		{
			return (*(--pString1) - *(--pString2));
		}
	}
}



