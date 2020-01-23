/*Program to perfrom delete operation on array*/
#include <stdio.h>
#include <stdlib.h>

/*
    * inserts element at the beginning of the array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePointer stores the addresss of the variable iArraySize
    *
    * @param Element the value of the element to be inserted
    *
    * @return void
*/
void insertAtBeginning(int aiArray[], int *pSizePointer, int iElement);

/*
    * inserts element in between the array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePointer stores the addresss of the variable iArraySize
    *
    * @param iElement the value of the element to be inserted
    *
    * @return void
*/
void insertInBetween(int aiArray[], int *pSizePointer, int iPosition, int iElement);

/*
    * inserts element at end of the array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePointer stores the addresss of the variable iArraySize
    *
    * @param iElement the value of the element to be inserted
    *
    * @return void
*/
void insertAtEnd(int aiArray[], int *pSizePointer, int iElement);

/*
    * prints the entire array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePointer stores the addresss of the variable iArraySize
    *
    * @return void
*/
void printArray(int aiArray[], int *pSizePointer);

void main()
{
    int aiArray[100] = {1, 2, 3, 4, 5};
    int iArraySize = 5;
    int iElement = 100;
    
    printArray(aiArray, &iArraySize);
    insertAtBeginning(aiArray, &iArraySize, iElement);
    printArray(aiArray, &iArraySize);
    insertInBetween(aiArray, &iArraySize, 3, iElement);
    printArray(aiArray, &iArraySize);   
    insertAtEnd(aiArray, &iArraySize, iElement);
    printArray(aiArray, &iArraySize);
}

void insertAtBeginning(int aiArray[], int *pSizePointer, int iElement)
{
    int iIndex;
    int iArraySize = (*pSizePointer)++;    //    increases the size of the array after inserting element
    
    for(iIndex = (iArraySize - 1); iIndex >= 0; iIndex--)
    {
        aiArray[iIndex + 1] = aiArray[iIndex];
    }

    aiArray[0] = iElement;
}

void insertInBetween(int aiArray[], int *pSizePointer, int iPosition, int iElement)
{
    int iIndex;
    int iArraySize = (*pSizePointer)++;    //    increases the size of the array after inserting element

    for(iIndex = (iArraySize - 1); iIndex >= iPosition; iIndex--)
    {
        aiArray[iIndex + 1] = aiArray[iIndex];    
    }

    aiArray[iIndex] = iElement;
}

void insertAtEnd(int aiArray[], int *pSizePointer, int iElement)
{
    int iArraySize = (*pSizePointer)++;    //    increases the size of the array after inserting element
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




