/*Program to swap two nos using xor operator*/
#include <stdio.h>
#define MAX 1000
#define MIN 0
#pragma message "**OTHER VALUE OTHER THAN INTEGER MAY CAUSE DATA LOSS**"

void main()
{
    int iFirstNumber;
    int iSecondNumber;
    int iFlag;  // stores the return value from scanf

    /*input*/
    printf("Enter first number [type: integer][range: %d to %d]: ", MIN, MAX);
    iFlag = ("%d", &iFirstNumber);

    /*validate input*/
    if(0 == iFlag)
    {
        printf("Invalid input\n");
        exit(0);
    }
    else if(iFirstNumber > MAX || iFirstNumber < MIN)
    {
        printf("Number out of range!!!\n");
        exit(0);
    }
    
    /*input*/ 
    printf("Enter second number [type: integer][range: %d to %d]: ", MIN, MAX);
    iFlag = ("%d", &iSecondNumber);

    /*validate input*/
    if(0 == iFlag)
    {
        printf("Invalid input\n");
        exit(0);
    }
    else if(iSecondNumber > MAX || iSecondNumber < MIN)
    {
        printf("Number out of range!!!\n");
        exit(0);
    }

    /*swapping*/
    iFirstNumber = iFirstNumber ^ iSecondNumber;
    iSecondNumber = iFirstNumber ^ iSecondNumber;
    iFirstNumber = iFirstNumber ^ iSecondNumber;

    /*print swapped value*/
    printf("First integer swapped value : %d\n", iFirstNumber);
    printf("Second integer swapped value : %d\n", iSecondNumber);
}
