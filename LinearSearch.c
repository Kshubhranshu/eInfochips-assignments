/*Program for linear search*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *pBaseAddressOfArray;   // stores the base address of the array allocated dynamically
    int iIndex;
    int iMaxSizeOfArray;    
    int iValueToSearch;

    printf("Enter the max size of array :   ");
    scanf("%d", &iMaxSizeOfArray);

    /*creates a dynamic array usng malloc*/
    pBaseAddressOfArray = (int*) malloc(iMaxSizeOfArray * sizeof(int));
    
    /*checks if memory allocated to array or not*/
    if (NULL == pBaseAddressOfArray)
    {
        printf("Memory not allocated. \n");
        exit(0);
    }
    else
    {   
        /*assignes random numbers to array*/
        printf("Randomly values allocated into array\n");
        for (iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
        {
            pBaseAddressOfArray[iIndex] = rand() % 100;
        }   
    }

    /*prints the array*/
    for(iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
    {
        printf("[%d]", pBaseAddressOfArray[iIndex]);
    }
    
    printf("\nEnter the element to search :   ");
    scanf("%d", &iValueToSearch);

    /*prints the index of the element found*/
    for(iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
    {
        if (iValueToSearch == pBaseAddressOfArray[iIndex])
        {
            printf("Element found at %d index\n", iIndex);
            exit(0);
        }
    }

    printf("Element not found!\n");
}
    
