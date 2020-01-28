/*Program to swap two nos using xor operator*/
#include <stdio.h>
#include <limits.h>

/*
* validates the inputs
*
* @param iValue
*
* @return void
*/
void validateInput(int iValue);

void main()
{
    int iFirstNumber;
    int iSecondNumber;

    int iFlag;  // stores the return value from scanf

    /*inputs*/
    printf("Enter first number [type: integer][range: %d to %d]: ", INT_MIN, INT_MAX);
    printf("%d", scanf("%d", &iFirstNumber));

    /*validate input*/
    validateInput(iFirstNumber);
    
    printf("Enter second number [type: integer][range: %d to %d]: ", INT_MIN, INT_MAX);
    scanf("%d", &iSecondNumber);

    /*validate input*/
    validateInput(iSecondNumber);
    /*swapping*/
    iFirstNumber = iFirstNumber ^ iSecondNumber;
    iSecondNumber = iFirstNumber ^ iSecondNumber;
    iFirstNumber = iFirstNumber ^ iSecondNumber;

    /*print swapped value*/
    printf("First integer swapped value : %d\n", iFirstNumber);
    printf("Second integer swapped value : %d\n", iSecondNumber);
}

void validateInput(int iValue)
{
    if(iValue < INT_MIN || iValue > INT_MAX)
    {
        printf("Invalid input\n");
        printf("Program terminated!!!\n");
    }
}