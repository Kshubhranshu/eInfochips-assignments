/*
3. Use InsertDataIn2DArray function which accept NxN Alphanumeric data from user. Use Sort2DArray function to sort 2D array in ascending order.
Note: use pass by pointer and dynamic memory allocation. Use pass by reference and fixed size of 2D array.
*/

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
#define N 10 	// maximum capacity of buffer

/*
	* this method takes the input from the user
	*
	* @param achBuffer is the reference to char array
	*
	* @param iSize stores the size of the buffer 
	*
	* @return void
*/
void insertData(char (&achBuffer)[N][N], int iSize);

/*
	* this mehtod prints the buffer
	*
	* @param achBuffer is the reference to char array
	*
	* @param iSize stores the size of the array
	*
	* @return void
*/
void printData(char (&achBuffer)[N][N], int iSize);

/*
	* this methods sorts the data buffer in ascending order
	*
	* @param pBufferPointer is pointer to pointer to char 
	*
	* @param iSize is the size of buffer
	*
	* @return void
*/
void sortBuffer(char (&achBuffer)[N][N], int iSize);

int main()
{
	int iIndex;
	int iSize;
	char achBuffer[N][N];

	cout << "Enter the size of bufffer [max buffer limit: N]: ";
	cin >> iSize;

	/*validate buffer max size*/
	if(iSize > N)
	{
		cout << "Exceeded buffer limit!!!" << endl;
		exit(EXIT_SUCCESS);
	}

	/*user input*/
	printf("Enter data into Buffer [dim: %d x %d][type: alphanumeric][max characters: %d + 1('\\0'null char)]\n", iSize, iSize, iSize - 1);
	insertData(achBuffer, iSize);
	cout << endl;

	/*prints the original buffer*/
	printf("Original Data Buffer\n");
	printData(achBuffer, iSize);
	cout << endl;

	/*sorts buffer*/
	sortBuffer(achBuffer, iSize);

	/*prints sorted data buffer*/
	printf("Sorted Data Buffer\n");
	printData(achBuffer, iSize);
	cout << endl;
}

void insertData(char (&achBuffer)[N][N], int iSize)
{
	int iIndex;

	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		int iTempIndex = 0;
		cin >> achBuffer[iIndex];

		/*validate characters count*/
		if(strlen(achBuffer[iIndex]) > iSize - 1)
		{
			cout << "Oops! Buffer limit exceeded!" << endl;
			exit(EXIT_SUCCESS);
		}

		/*validate alphanumeric input*/
		while(achBuffer[iIndex][iTempIndex])
		{
			if(!(isalnum(achBuffer[iIndex][iTempIndex])))
			{
				cout << "Invalid Character type! Not an alphanumberic character!" << endl;
				exit(EXIT_SUCCESS);
			}
			iTempIndex++;
		}
	}
}

void printData(char (&achBuffer)[N][N], int iSize)
{
	int iIndex;
	
	for(iIndex = 0; iIndex < iSize; iIndex++)
	{
		cout << achBuffer[iIndex] << endl;
	}
}

void sortBuffer(char (&achBuffer)[N][N], int iSize)
{
	int iIndexI;
	int iIndexJ;
	char achTempBuffer[N];

	/*sorting operation*/
    for(iIndexI = 0; iIndexI < iSize - 1; iIndexI++)
	{
		for(iIndexJ = 0; iIndexJ < iSize - iIndexI - 1; iIndexJ++)
		{
			if(strcmp(achBuffer[iIndexJ], achBuffer[iIndexJ + 1]) > 0)
			{
				strcpy(achTempBuffer, achBuffer[iIndexJ]);
				strcpy(achBuffer[iIndexJ], achBuffer[iIndexJ + 1]);
				strcpy(achBuffer[iIndexJ + 1], achTempBuffer);
			}
		}
	}
}
