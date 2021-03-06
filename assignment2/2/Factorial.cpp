/*
statement: 2. Ask to the user to enter the number to find the factorial of the number and display the factorial result of the numbe. Note: use pass by pointer and pass by reference.
*/

#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
#define MIN 0

/*
	* @id 2.1
	*
    * this methods prints the factorial of a number, but the parameter is pass by pointer to variable
    *
    * @param pNumber is a pointer to variable
    *
    * @return long int
*/
unsigned long int getFactorialPtr(int *pNumber);

/*
	* @id 2.2
	*
    * this methods returns the factorial of a number, but the parameter is pass by reference to variable
    *
    * @param rNumber is a reference to variable 
    *
    * @return long int
*/
unsigned long int getFactorialRef(int &rNumber);

int main()
{
	int iNumber;
	unsigned long int iFactorialResult;

	printf("Enter the number [range: %d - %d]: ", MIN, MAX);	
	std :: cin >> iNumber;

	/*validate negative input*/
	if(iNumber < MIN || iNumber > MAX)
	{
		std :: cout << "Input invalid! Number out of range!!" << endl;
		exit(ERANGE);	
	}

	/*function call by pointer to variable*/
	iFactorialResult = getFactorialPtr(&iNumber);			
	std :: cout << "Factorial of " << iNumber << " [param: pointer to variable]" << "   = " << iFactorialResult << endl;

	/*function call by reference to variable*/
	iFactorialResult = getFactorialRef(iNumber);
	std :: cout << "Factorial of " << iNumber << " [param: reference to variable]" << " = " << iFactorialResult << endl;

}

unsigned long int getFactorialPtr(int *pNumber)
{
	unsigned long int iFactorialResult = 1;
	int iNumber = (*pNumber);

	/*factorial calcultaion*/
	/*factorial calcultaion*/
	while(iNumber)
	{	
		if(iNumber < 1)
		{
			return iFactorialResult;
		}

		iFactorialResult *= iNumber;
		iNumber--;
	}
}

unsigned long int getFactorialRef(int &rNumber)
{
	unsigned long int iFactorialResult = 1;
	int iNumber = rNumber;

	/*factorial calculation*/	
	while(iNumber)
	{
		if(iNumber < 1)
		{
			return iFactorialResult;
		}

		iFactorialResult *= iNumber;
		iNumber--;
	}
} 
