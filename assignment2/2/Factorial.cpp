/*
* 2. Ask to the user to enter the number to find the factorial of the number and display the factorial result of the numbe. Note: use pass by pointer and pass by reference.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
    * this methods prints the factorial of a number, but the parameter is pass by pointer
    *
    * @param pNumber is a pointer to variable
    *
    * @return int
*/
int getFactorialPtr(int *pNumber);

/*
    * this methods returns the factorial of a number, but the parameter is pass by reference
    *
    * @param rNumber is a reference to variable 
    *
    * @return int
*/
int getFactorialRef(int &rNumber);

int main()
{
	int iNumber;
	long int iFactorialResult;

	cout << "Enter a number[input: pointer to variable]: ";
	cin >> iNumber;

	/*validate input*/
	if(iNumber < 0)
	{
		cout << "Input invalid! Number can't be negative" << endl;
		exit(EXIT_SUCCESS);
	}

	/*function call by pointer*/
	iFactorialResult = getFactorialPtr(&iNumber);
	cout << "Factorial of " << iNumber << " = " << iFactorialResult << endl;

	cout << "Enter a number[input: reference to variable]: ";
	cin >> iNumber;
	
	/*validate input*/
	if(iNumber < 0)
	{	
		cout << "Input invalid! Number can't be negative" << endl;
		exit(EXIT_SUCCESS);
	}

	/*function call by reference*/
	iFactorialResult = getFactorialRef(iNumber);
	cout << "Factorial" << iNumber << " = " << iFactorialResult << endl;

}

int getFactorialPtr(int *pNumber)
{
	long int iFactorialResult = 1;
	int iNumber = (*pNumber);

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

int getFactorialRef(int &rNumber)
{
	long int iFactorialResult = 1;

	/*factorial calculation*/	
	while(rNumber)
	{
		if(rNumber < 1)
		{
			return iFactorialResult;
		}

		iFactorialResult *= rNumber;
		rNumber--;
	}
} 
