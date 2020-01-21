#include <stdio.h>

void main()
{
    int iHighestSetBit = 0;
    int iNoOfLeadingZeroes;
    int iNumber = 10;
    
    while(iNumber >> (iHighestSetBit++));
    iNoOfLeadingZeroes = (sizeof(iNumber) * 8) - (iHighestSetBit - 1);
    printf("No of leading zeroes in %d is %d\n", iNumber, iNoOfLeadingZeroes);
}