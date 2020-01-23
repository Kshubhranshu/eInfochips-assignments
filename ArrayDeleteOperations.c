/*Program to perfrom insert operation on array*/
#include <stdio.h>

/*
    * deletes the first element of the array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePtr stores the addresss of the variable iArraySize
    *
    * @return void
*/
void deleteFromStart(int aiArray[], int *pSizePtr);

/*
    * deletes the last element of the array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePtr stores the addresss of the variable iArraySize
    *
    * @return void
*/
void deleteFromEnd(int aiArray[], int *pSizePtr);

/*
     deletes the in between element of the array
    *
     @param aiArray[] is the actual array
    *
     @param pSizePtr stores the addresss of the variable iArraySize
    *
     @param iPositin is the index of the element to be deleted
    *
     @return void
*/
void deleteFromBetween(int aiArray[], int *pSizePtr, int iPostiton);

/*
    * pritns the entire array
    *
    * @param aiArray[] is the actual array
    *
    * @param pSizePtr stores the addresss of the variable iArraySize
    *
    * @return void
*/
void printArray(int aiArray[], int *pSizePtr);

void main()
{
    int aiArray[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    int iSizeOfArray = 8;

    printf("Enter the size of array : ");
    scanf("%d", &iSizeOfArray);

    /*prints the original array*/
    printArray(aiArray, &iSizeOfArray);

    /*delets the last element*/
    deleteFromEnd(aiArray, &iSizeOfArray);

    /*prints the modified array*/
    printArray(aiArray, &iSizeOfArray);

    /*delets the first elements*/
    deleteFromStart(aiArray, &iSizeOfArray);

    /*prints the modified array*/
    printArray(aiArray, &iSizeOfArray);

    /*delets the element at given position*/
    deleteFromBetween(aiArray, &iSizeOfArray, 3);

    /*prints the modified array*/
    printArray(aiArray, &iSizeOfArray);
}

void deleteFromStart(int aiArray[], int *pSizePtr)
{
    int iIndex;
    int iSizeOfArray = --(*pSizePtr);   //  decreases the size of the array on deletion

    for(iIndex = 0; iIndex < iSizeOfArray; iIndex++)
    {
        aiArray[iIndex] = aiArray[iIndex + 1];
    }
}

void deleteFromEnd(int aiArray[], int *pSizePtr)
{
    (*pSizePtr)--;   //  decreases the size of the array on deletion
}

void deleteFromBetween(int aiArray[], int *pSizePtr, int iPosition)
{
    int iIndex;
    int iSizeOfArray = (*pSizePtr)--;   //  decreases the size of the array on deletion

    for(iIndex = iPosition; iIndex < (iSizeOfArray - 1); iIndex++)
    {
        aiArray[iIndex] = aiArray[iIndex + 1];
    }
}

void printArray(int aiArray[], int *pSizePointer)
{
    int iIndex;
    int iSizeOfArray = (*pSizePointer);    //  decreases the size of the array on deletion

    for(iIndex = 0; iIndex < iSizeOfArray; iIndex++)
    {
        printf("%d", aiArray[iIndex]);
    }

    printf("\n");
}
