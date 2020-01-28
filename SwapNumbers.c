/*Program to swap two nos using xor operator*/
#include<stdio.h>

void main()
{
    int iFirstNumber;
    int iSecondNumber;

    printf("Enter first and second integers   : ");
    scanf("%d %d", &iFirstNumber, &iSecondNumber);

    /*swapping*/
    iFirstNumber = iFirstNumber ^ iSecondNumber;
    iSecondNumber = iFirstNumber ^ iSecondNumber;
    iFirstNumber = iFirstNumber ^ iSecondNumber;
}