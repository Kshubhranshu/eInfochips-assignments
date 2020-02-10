#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

/*
	* this method takes the input from the user
	*
	* @param pBufferPointer is the pointer to char array
	*
	* @param iSize stores the size of the buffer 
	*
	* @return void
*/
void insertData(char **pBufferPointer, int iSize);

/*
	* this mehtod prints the buffer
	*
	* @param pBufferPointer is the pointer to the char array
	*
	* @param iSize stores the size of the array
	*
	* @return void
*/
void printData(char **pBufferPointer, int iSize);

/*
	* this methods sorts the data buffer in ascending order
	*
	* @param pBufferPointer is pointer to pointer to char 
	*
	* @param iSize is the size of buffer
	*
	* @return void
*/
void sortBuffer(char **pBufferPointer, int iSize);

int main()
{
	int iIndex;
	int iSize;
	char **pBufferPointer = NULL;

	cout << "Enter the size of bufffer: ";
	cin >> iSize;
	
	/*arr for storing rows*/
	pBufferPointer = new char *[iSize];

	/*arr for storing columns*/
	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		pBufferPointer[iIndex] = new char [iSize];
	}

	/*validate buffer pointer*/
	if(NULL == pBufferPointer)
	{
		cout << "Memory not allocated!!" << endl;
		exit(EXIT_SUCCESS);
	}

	/*user input*/
	printf("Enter data into Buffer [dim: %d x %d][type: alphanumeric]\n", iSize, iSize);
	insertData(pBufferPointer, iSize);
	cout << endl;

	/*prints the original buffer*/
	printf("Original Data Buffer [%d x %d]\n", iSize, iSize);
	printData(pBufferPointer, iSize);
	cout << endl;

	/*sorts buffer*/
	sortBuffer(pBufferPointer, iSize);

	/*prints sorted data buffer*/
	printf("Sorted Data Buffer [%d x %d]\n", iSize, iSize);
	printData(pBufferPointer, iSize);
	cout << endl;
}

void insertData(char **pBufferPointer, int iSize)
{
	int iIndex;

	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		int iTempIndex;
		cin >> pBufferPointer[iIndex];

		/*validate characters count*/
		if(strlen(pBufferPointer[iIndex]) > iSize - 1)
		{
			cout << "Oops! Buffer limit exceeded!" << endl;
			exit(EXIT_SUCCESS);
		}

		/*validate alphanumeric input*/
		//currently working here
		/*
		while(pBufferPointer[iTempIndex])
		{
			if(!(isalnum(pBufferPointer[iTempIndex])))
			{
				cout << "Invalid Character type! Not an alphanumberic character!" << endl;
				exit(EXIT_SUCCESS);
			}
			iTempIndex++;
		}
		*/
	}
}

void printData(char **pBufferPointer, int iSize)
{
	int iIndex;
	
	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		cout << pBufferPointer[iIndex] << endl;
	}
}

void sortBuffer(char **pBufferPointer, int iSize)
{
	int iIndexI;
	int iIndexJ;

	/*sorting operation*/
	for(iIndexI = 0; iIndexI < (iSize - 1); iIndexI++)
	{
		for(iIndexJ = 0; iIndexJ < (iSize - iIndexJ - 1); iIndexJ++)
		{
			if(strcmp(pBufferPointer[iIndexJ], pBufferPointer[iIndexJ + 1]) > 0)
			{
				/*swapping*/
				char *pTempBufferPointer = new char[iSize];
				strcpy(pTempBufferPointer, pBufferPointer[iIndexJ]);
				strcpy(pBufferPointer[iIndexJ], pBufferPointer[iIndexJ + 1]);
				strcpy(pBufferPointer[iIndexJ], pTempBufferPointer);
			}
		}
	}
}
