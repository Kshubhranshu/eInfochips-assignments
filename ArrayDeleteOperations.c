/*Program to perfrom insert operation on array*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define RED printf("\x1b[31;40m");
#define RESET printf("\x1b[m");


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

/*
    * checks if the array is empty
    *
    * @param iArraySize;
    *
    * @return int
*/
int isEmpty(int iArraySize);

void main()
{
    int aiArray[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    int iArraySize = 8;
    int iPosition;

    while(1)
    {   
        int iChoice;

        /*menu for array insertion operations*/
        printf("Array Delete Operations Menu\n");
        printf("1. Delete element at beginning of the array\n");
        printf("2. Delete element in the middle of the array\n");
        printf("3. Delete element at the end of the array\n");
        printf("4. Print the array\n");
        printf("0. Exit\n");
        printf("Make a selection    : ");
        scanf("%d", &iChoice);

        /*validation check if the array is empty*/
        if(isEmpty(iArraySize) &&  1 == iChoice || 2 == iChoice || 3 == iChoice)
        {
            
            RED
            printf("Array empty cannot delete anymore!!\n");
            RESET

            break;
        }

        switch(iChoice)
        {
            case 0:
                    /*program termination*/
                    exit(0);

            case 1:
                    /*delete from beginning*/
                    deleteFromStart(aiArray, &iArraySize);
                    break;

            case 2:
                    /*delete in between*/
                    printf("Enter the position : ");
                    scanf("%d", &iPosition);
                    deleteFromBetween(aiArray, &iArraySize, iPosition);
                    break;

            case 3:
                    /*delete from end*/
                    deleteFromEnd(aiArray, &iArraySize);
                    break;

            case 4:
                    /*check if array is empty*/
                    if(iArraySize == 0)
                    {
                        printf("Array Empty, Nothing to print.\n");
                    }

                    /*prints array*/
                    printArray(aiArray, &iArraySize);
                    break;

            default:
                    /*invalid input*/
                    printf("Invalid Selection!\n");
                    break;
        }
        printf("\n");
    }
}

void deleteFromStart(int aiArray[], int *pSizePtr)
{
    int iIndex;
    int iArraySize = --(*pSizePtr);   //  decreases the size of the array on deletion

    for(iIndex = 0; iIndex < iArraySize; iIndex++)
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
    int iArraySize = (*pSizePtr)--;   //  decreases the size of the array on deletion

    for(iIndex = iPosition; iIndex < (iArraySize - 1); iIndex++)
    {
        aiArray[iIndex] = aiArray[iIndex + 1];
    }
}

void printArray(int aiArray[], int *pSizePointer)
{
    int iIndex;
    int iArraySize = (*pSizePointer);    //  decreases the size of the array on deletion

    for(iIndex = 0; iIndex < iArraySize; iIndex++)
    {
        printf("[%d]", aiArray[iIndex]);
    }

    printf("\n");
}

int isEmpty(int iArraySize)
{
    if(0 == iArraySize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
