/*
statement: 3. Use InsertDataIn2DArray function which accept NxN Alphanumeric data from user. Use Sort2DArray function to sort 2D array in ascending order.
Note: (a) use pass by pointer and dynamic memory allocation. (b) Use pass by reference and fixed size of 2D array.
*/

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

/*
	* @id 3.a.1
	*
	* this method takes the input from the user
	*
	* @param pBufferPointer is the pointer to pointer to char array
	*
	* @param iSize stores the size of the buffer 
	*
	* @return void
*/
void insertData(char **pBufferPointer, int iSize);

/*
	* @id 3.a.2
	*
	* this mehtod prints the buffer
	*
	* @param pBufferPointer is the pointer to pointer to the char array
	*
	* @param iSize stores the size of the array
	*
	* @return void
*/
void printData(char **pBufferPointer, int iSize);

/*
	* @id 3.a.3
	*
	* this method sorts the data buffer in ascending order
	*
	* @param pBufferPointer is pointer to pointer to char 
	*
	* @param iSize is the size of buffer
	*
	* @return void
*/
void sortBuffer(char **pBufferPointer, int iSize);

/*
	* @id 3.a.4
	*
	* this method deallocates the memory
	*	
	* @param pBufferPointer
	*
	* @param iSize
	*
	* @return void
*/
void deallocateMemeory(char **pBufferPointer, int iSize);

int main()
{
	int iIndex;
	int iSize;
	char **pBufferPointer = NULL;

	std :: cout << "Enter the size of bufffer: ";
	std :: cin >> iSize;
	
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
		std :: cout << "Memory not allocated!!" << endl;
		exit(EXIT_SUCCESS);
	}

	/*user input*/
	printf("Enter data into Buffer [dim: %d x %d][type: alphanumeric][max characters: %d + 1('\\0'null char)]\n", iSize, iSize, iSize - 1);
	insertData(pBufferPointer, iSize);
	std :: cout << endl;

	/*prints the original buffer*/
	printf("Original Data Buffer\n");
	printData(pBufferPointer, iSize);
	std :: cout << endl;

	/*sorts buffer*/
	sortBuffer(pBufferPointer, iSize);

	/*prints sorted data buffer*/
	printf("Sorted Data Buffer\n");
	printData(pBufferPointer, iSize);
	std :: cout << endl;

	
}

void insertData(char **pBufferPointer, int iSize)
{
	int iIndex;

	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		int iTempIndex = 0;
		std :: cin >> pBufferPointer[iIndex];

		/*validate characters count*/
		if(strlen(pBufferPointer[iIndex]) > iSize - 1)
		{
			std :: cout << "Oops! Buffer limit exceeded!" << endl;
			deallocateMemeory(pBufferPointer, iSize);

			exit(EOVERFLOW);
		}

		/*validate alphanumeric input*/
		while(pBufferPointer[iIndex][iTempIndex])
		{
			if(!(isalnum(pBufferPointer[iIndex][iTempIndex])))
			{
				std :: cout << "Invalid Character type! Not an alphanumberic character!" << endl;
				deallocateMemeory(pBufferPointer, iSize);
				
				exit(EIO);
			}
			iTempIndex++;
		}
	}
}

void printData(char **pBufferPointer, int iSize)
{
	int iIndex;
	
	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		std :: cout << pBufferPointer[iIndex] << endl;
	}
}

void sortBuffer(char **pBufferPointer, int iSize)
{
	int iIndexI;
	int iIndexJ;
	char *pTempBuffer;

	/*sorting operation*/
    for(iIndexI = 0; iIndexI < iSize - 1; iIndexI++)
	{
		for(iIndexJ = 0; iIndexJ < iSize - iIndexI - 1; iIndexJ++)
		{
			if(strcmp(pBufferPointer[iIndexJ], pBufferPointer[iIndexJ + 1]) > 0)
			{
				/*initialize pointer to array to null*/
				pTempBuffer = new char[iSize];
				memset(pTempBuffer, NULL, iSize * sizeof(pTempBuffer[0]));

				/*swapping*/
				strcpy(pTempBuffer, pBufferPointer[iIndexJ]);
				strcpy(pBufferPointer[iIndexJ], pBufferPointer[iIndexJ + 1]);
				strcpy(pBufferPointer[iIndexJ + 1], pTempBuffer);
				
				/*deallocate memory*/
				delete []pTempBuffer;
			}
		}
	}
}

void deallocateMemeory(char **pBufferPointer, int iSize)
{
	int iIndex;

	/*free sub buffer*/
	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		delete[] pBufferPointer[iIndex];
	}

	/*free buffer pointer*/
	delete[] pBufferPointer;
}
