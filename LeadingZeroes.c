/*Program to count the number of leading zeroes*/
#include <stdio.h>

void main()
{
    int iHighestSetBit = 0;     //  stores the position of highest set bit
    int iNoOfLeadingZeroes;     //  stores the result of leading zeroes
    int iNumber;           
    
    printf("Enter the number    : ");
    scanf("%d", &iNumber);

    /*counts the position of highest set bit using right shift*/
    while(iNumber >> (iHighestSetBit++));

    /*calculates the no of leading zeroes*/
    iNoOfLeadingZeroes = (sizeof(iNumber) * 8) - (iHighestSetBit - 1);

    /*prints the no of leading zeroes*/
    printf("No of leading zeroes in %d is %d\n", iNumber, iNoOfLeadingZeroes);
}