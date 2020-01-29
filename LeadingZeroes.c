/*Program to count the number of leading zeroes*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define MIN 0
#pragma message "**OTHER VALUE OTHER THAN INTEGER MAY CAUSE DATA LOSS**"


void main()
{
    int iHighestSetBit;     //  stores the position of highest set bit
    int iNoOfLeadingZeroes;     //  stores the result of leading zeroes
    int iNumber;
    int iFlag;  // stores the return value from scanf

    iHighestSetBit = 0; // initial value as 0           
    
    printf("Enter the number [type: integer][range: %d to %d]: ", MIN, MAX);
    iFlag = scanf("%d", &iNumber);

    /*validate input*/
    if(0 == iFlag)  
    {
        printf("Invalid input\n");
        exit(0);
    }
    if(iNumber > MAX || iNumber < MIN)
    {
        printf("Number out of range!!!\n");
        exit(0);
    }

    /*counts the position of highest set bit using right shift*/
    while(iNumber >> (iHighestSetBit++));

    /*calculates the no of leading zeroes*/
    iNoOfLeadingZeroes = (sizeof(iNumber) * 8) - (iHighestSetBit - 1);

    /*prints the no of leading zeroes*/
    printf("No of leading zeroes in %d is %d\n", iNumber, iNoOfLeadingZeroes);
}