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
    int aiArray[100];
    int iArraySize = 0;
    int iElement;
    int iPosition;

    while(1)
    {   
        int iChoice;

        /*menu for array insertion operations*/
        printf("Array Insert Operations Menu\n");
        printf("1. Insert element at beginning of the array\n");
        printf("2. Insert element in the middle of the array\n");
        printf("3. Insert element at the end of the array\n");
        printf("4. Print the array\n");
        printf("0. Exit\n\n");
        printf("Make a selection    : ");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
        case 0:
                exit(0);
        
        case 1:
                /*insert at beginning*/
                printf("Enter the value to insert : ");
                scanf("%d", &iElement);
                insertAtBeginning(aiArray, &iArraySize, iElement);
                break;

        case 2:
                /*insert in between*/
                printf("Enter the value to insert : ");
                scanf("%d", &iElement);
                printf("Enter the position : ");
                scanf("%d", &iPosition);
                insertInBetween(aiArray, &iArraySize, iPosition, iElement);
                break;

        case 3:
                /*insert at end*/
                printf("Enter the value to insert : ");
                scanf("%d", &iElement);
                insertAtEnd(aiArray, &iArraySize, iElement);
                break;

        case 4:
                /*check if array is empty*/
                if(iArraySize == 0)
                {
                    printf("Array Empty, Insert an element first.\n");
                }

                /*prints array*/
                printArray(aiArray, &iArraySize);
                break;
        
        default:
                printf("Invalid Selection!\n");
                break;
        }
        printf("\n");
    }
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



