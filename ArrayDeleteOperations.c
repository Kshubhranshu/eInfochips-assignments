#include <stdio.h>

void deleteFromStart(int aiArray[], int *pSizePtr);
void deleteFromEnd(int aiArray[], int *pSizePtr);
void deleteFromBetween(int aiArray[], int *pSizePtr, int iPostiton);
void printArray(int aiArray[], int *pSizePtr);

void main()
{
    int aiArray[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    int iSizeOfArray = 8;

    printf("Enter the size of array : ");
    scanf("%d", &iSizeOfArray);
    printArray(aiArray, &iSizeOfArray);
    deleteFromEnd(aiArray, &iSizeOfArray);
    printArray(aiArray, &iSizeOfArray);
    deleteFromStart(aiArray, &iSizeOfArray);
    printArray(aiArray, &iSizeOfArray);
    deleteFromBetween(aiArray, &iSizeOfArray, 3);
    printArray(aiArray, &iSizeOfArray);
}

void deleteFromStart(int aiArray[], int *pSizePtr)
{
    int iIndex;
    int iSizeOfArray = --(*pSizePtr);

    for(iIndex = 0; iIndex < iSizeOfArray; iIndex++)
    {
        aiArray[iIndex] = aiArray[iIndex + 1];
    }
}

void deleteFromEnd(int aiArray[], int *pSizePtr)
{
    (*pSizePtr)--;   
}

void deleteFromBetween(int aiArray[], int *pSizePtr, int iPosition)
{
    int iIndex;
    int iSizeOfArray = (*pSizePtr)--;

    for(iIndex = iPosition; iIndex < (iSizeOfArray - 1); iIndex++)
    {
        aiArray[iIndex] = aiArray[iIndex + 1];
    }
}

void printArray(int aiArray[], int *pSizePointer)
{
    int iIndex;
    int iSizeOfArray = (*pSizePointer);

    for(iIndex = 0; iIndex < iSizeOfArray; iIndex++)
    {
        printf("%d", aiArray[iIndex]);
        //
    }
    printf("\n");
}
