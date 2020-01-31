/*
4.a. Make a program to insert an element into array (at beginning, in between or at last)
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100   // array max size limit
#define RED printf("\x1b[31;40m");
#define RESET printf("\x1b[m");

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

/*
    * checks if the array is full
    *
    * @param iArraySize;
    *
    * @return int
*/
int isFull(int iArraySize);

void main()
{
    int aiArray[N];
    int iArraySize = 0;     // counter for counting no of elements currently preseent in arary initial count value = 0
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

        /*validation check if the array is full*/
        if(isFull(iArraySize) &&  1 == iChoice || 2 == iChoice || 3 == iChoice)
        {
            RED
            printf("Array full cannot insert element!!\n");
            RESET

            break;
        }

        switch(iChoice)
        {
        case 0: 
                /*program termination*/
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

                /*validate position*/
                if((iPosition > iArraySize - 1) || (iPosition < 0))
                {
                    printf("Oops! Invalid Position\n");
                    break;
                }

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
                if(0 == iArraySize)
                {
                    printf("Array Empty, Insert an element first.\n");
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

int isFull(int iArraySize)
{
    if(N == iArraySize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




