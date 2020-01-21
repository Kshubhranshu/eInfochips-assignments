#include <stdio.h>
#include <stdlib.h>

void insertAtBegining(int iaArray[], int iArraySize, int iElement);
void insertInBetween(int iaArray[], int iArraySize, int iPosition, int iElement);
void insertAtEnd(int iaArray[], int iArraySize, int iElement);

void deleteAtBegining(int iaArray[], int iArraySize);
void deleteInBetween(int iaArray[], int iArraySize, int iPosition);
void deleteAtEnd(int iaArray[], int iArraySize);

void printArray(int iaArray[], int iArraySize);

void main()
{
    int iaArray[100] = {1, 2, 3, 4, 5};
    int iArraySize = 5;
    int iElement = 10;
    insertAtBegining(iaArray, iArraySize, iElement);
    printf("%lu", sizeof(iaArray));
}

void insertAtBegining(int iaArray[], int iArraySize, int iElement)
{
    int iIndex;
    
    for(iIndex = (iArraySize - 1); iIndex >= 0; iIndex--)
    {
        iaArray[iIndex + 1] = iaArray[iIndex];
        // 
    }
    iaArray[0] = iElement;
}

void insertInBetween(int iaArray[], int iArraySize, int iPosition, int iElement)
{
    int iIndex;

    for(iIndex = (iArraySize - 1); iIndex >= iPosition; iIndex--)
    {
        iaArray[iIndex + 1] = iaArray[iIndex];    
        //
    }
    iaArray[iIndex] = iElement;
}

void insertAtEnd(int iaArray[], int iArraySize, int iElement)
{
    iaArray[iArraySize] = iElement;
}

void printArray(int iaArray[], int iArraySize)
{
    int iIndex;

    for(iIndex = 0; iIndex < iArraySize; iIndex++)
    {
        printf("[%d]", iaArray[iIndex]);
    }
    //
}

void deleteAtBegining(int iaArray[], int iArraySize)
{
    
}



