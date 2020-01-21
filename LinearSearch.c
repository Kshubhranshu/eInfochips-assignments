#include<stdio.h>
#include<stdlib.h>

void main()
{
    int* ptrBaseAddressOfArray;   /*stores the base address of the array allocated dynamically*/
    int iIndex;
    int iMaxSizeOfArray;
    int iValueToSearch;

    printf("Enter the max size of array :   ");
    scanf("%d", &iMaxSizeOfArray);
    ptrBaseAddressOfArray = (int*) malloc(iMaxSizeOfArray * sizeof(int));
    
    if (ptrBaseAddressOfArray == NULL)
    {
        printf("Memory not allocated. \n");
        exit(0);
    }
    else
    {
        for (iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
        {
            ptrBaseAddressOfArray[iIndex] = rand() % 100;
            //
        }   
    }

    for(iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
    {
        printf("[%d]", ptrBaseAddressOfArray[iIndex]);
        //
    }
    
    printf("\nEnter the element to search :   ");
    scanf("%d", &iValueToSearch);
    for(iIndex = 0; iIndex < iMaxSizeOfArray; iIndex++)
    {
        if (iValueToSearch == ptrBaseAddressOfArray[iIndex])
        {
            printf("Element found at %d index\n", iIndex);
            exit(0);
        }
        //
    }
    printf("Element not found!\n");
}
    
