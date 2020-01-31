/*
3.b. Program for Binary Search using Array
*/

#include<stdio.h>
#include<stdlib.h>
#define N 100
#define RED printf("\x1b[31;40m");
#define RESET printf("\x1b[m");

/*
    * finds the element in the array
    *
    * @param aiArray[] is the actual array
    *
    * @param iSizeOfArray is the size of the arrray
    *
    * @param iValueToSearch is the element to search in the array
    *
    * @return return the index of the element
*/
int binarySearch(int aiArray[], int iSizeOfArray, int iValueToSearch);

/*
    * mehtod for sorting the array in ascending orer
    *
    * @param aiArray[] is the actual array
    *
    * @param iSizeOfArray is the size of the arrray
    *
    * @return void
*/
void sortArray(int aiArray[], int iSizeOfArray);

/*
    * mehtod for printing the array
    *
    * @param aiArray[] is the actual array
    *
    * @param iSizeOfArray is the size of the arrray
    *
    * @return void
*/
void printArray(int aiArray[], int iSizeOfArray);

/*
    * mehtod for array input
    *
    * @param aiArray[] is the actual array
    *
    * @param iSizeOfArray is the size of the arrray
    *
    * @return void
*/
void getInput(int aiArray[], int iSizeOfArray);

void main()
{
    int aiArray[N];
    int iSizeOfArray;
    int iValueToSearch; 
    int iBinarySearchResult;    //  stores the index of found element

    printf("Enter the size of array[max cap: %d] : ", N);
    scanf("%d", &iSizeOfArray);

    /*validate max array size*/
    if(iSizeOfArray > N)
    {
        RED
        printf("Maximum capacity limit exceeded!!!\n");
        RESET
        
        exit(0);
    }

    /*input array*/
    printf("Enter %d elements into array\n", iSizeOfArray);
    getInput(aiArray, iSizeOfArray);
    printf("\n");

    /*prints original array*/
    printf("Original Array    :   ");
    printArray(aiArray, iSizeOfArray);
    printf("\n");


    /*sorts the array*/
    sortArray(aiArray, iSizeOfArray);

    /*prints the sorted array*/
    printf("Sorted Array      :   ");
    printArray(aiArray, iSizeOfArray);
    printf("\n");
    
    printf("Enter the value to search   : ");
    scanf("%d", &iValueToSearch);

    /*stores the return value from binarySearch*/
    iBinarySearchResult = binarySearch(aiArray, iSizeOfArray, iValueToSearch);

    /*checks if the element exist in the araay or not*/
    if (-1 == iBinarySearchResult)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at %d index\n", iBinarySearchResult);
    }
}

int binarySearch(int aiArray[], int iSizeOfArray, int iValueToSearch)
{
    int iStartIndex = 0;
    int iEndIndex = iSizeOfArray - 1;
    int iMidIndex;

    while (iStartIndex <= iEndIndex)
    {
        iMidIndex = (iStartIndex + iEndIndex) / 2;

        if (aiArray[iMidIndex] == iValueToSearch)
        {
            return iMidIndex;
        }
        else if (iValueToSearch > aiArray[iMidIndex])
        {
            iStartIndex = iMidIndex + 1;
        }
        else if (iValueToSearch < aiArray[iMidIndex])
        {
            iEndIndex = iMidIndex - 1; 
        }
    }

    return -1;    
}

void sortArray(int aiArray[], int iSizeOfArray)
{
    int iIndexI;
    int iIndexJ;
    int iTemp;  // temp variable for swapping

    for(iIndexI = 0; iIndexI < iSizeOfArray - 1; iIndexI++)
    {
        for(iIndexJ = 0; iIndexJ < (iSizeOfArray - iIndexI - 1); iIndexJ++)
        {
            if(aiArray[iIndexJ] > aiArray[iIndexJ + 1])
            {   
                
                /*swapping*/
                iTemp = aiArray[iIndexJ];
                aiArray[iIndexJ] = aiArray[iIndexJ+1];
                aiArray[iIndexJ+1] = iTemp;
            }
        }
    }
}

void printArray(int aiArray[], int iSizeOfArray)
{
    int iIndex;
    for (iIndex= 0; iIndex < iSizeOfArray; iIndex++)
    {
        printf("%d  ", aiArray[iIndex]);
    }
}

void getInput(int aiArray[], int iSizeOfArray)
{
    int iIndex;

    for(iIndex = 0; iIndex < iSizeOfArray; iIndex++)
    {
        scanf("%d", &aiArray[iIndex]);
    }
}
