#include <stdio.h>
#include <stdlib.h>

void insertAtBegining(int aiArray[], int *pSizePointer, int iElement);
void insertInBetween(int aiArray[], int *pSizePointer, int iPosition, int iElement);
void insertAtEnd(int aiArray[], int *pSizePointer, int iElement);
void printArray(int aiArray[], int *pSizePointer);

void main()
{
    int aiArray[100] = {1, 2, 3, 4, 5};
    int iArraySize = 5;
    int iElement = 100;
    
    printArray(aiArray, &iArraySize);

    insertAtBegining(aiArray, &iArraySize, iElement);
    printArray(aiArray, &iArraySize);

    insertInBetween(aiArray, &iArraySize, 3, iElement);
    printArray(aiArray, &iArraySize);

    insertAtEnd(aiArray, &iArraySize, iElement);
    printArray(aiArray, &iArraySize);
}

void insertAtBegining(int aiArray[], int *pSizePointer, int iElement)
{
    int iIndex;
    int iArraySize = (*pSizePointer)++;
    
    for(iIndex = (iArraySize - 1); iIndex >= 0; iIndex--)
    {
        aiArray[iIndex + 1] = aiArray[iIndex];
    }
    aiArray[0] = iElement;
}

void insertInBetween(int aiArray[], int *pSizePointer, int iPosition, int iElement)
{
    int iIndex;
    int iArraySize = (*pSizePointer)++;

    for(iIndex = (iArraySize - 1); iIndex >= iPosition; iIndex--)
    {
        aiArray[iIndex + 1] = aiArray[iIndex];    
    }
    aiArray[iIndex] = iElement;
}

void insertAtEnd(int aiArray[], int *pSizePointer, int iElement)
{
    int iArraySize = (*pSizePointer)++;
    aiArray[iArraySize] = iElement;
}

void printArray(int aiArray[], int *pSizePointer)
{
    int iIndex;
    int iArraySize = (*pSizePointer);

    for(iIndex = 0; iIndex < iArraySize; iIndex++)
    {
        printf("[%d]", aiArray[iIndex]);
    }
    printf("\n");
}




