#include<stdio.h>

void main()
{
    int iFirstNumber;
    int iSecondNumber;

    printf("Enter first and second number   : ");
    scanf("%d %d", &iFirstNumber, &iSecondNumber);

    /*swapping*/
    iFirstNumber = iFirstNumber ^ iSecondNumber;
    iSecondNumber = iFirstNumber ^ iSecondNumber;
    iFirstNumber = iFirstNumber ^ iSecondNumber;
}