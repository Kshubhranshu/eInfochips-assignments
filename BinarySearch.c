#include<stdio.h>
#include<stdlib.h>

int binarySearch(int iaArray[], int iSizeOfArray, int iValueToSearch);
void sortArray(int iaArray[], int iSizeOfArray);

void main()
{
    int iaArray[100] = {8,6,5,4,3,2,1,3,4};
    int iSizeOfArray;
    int iValueToSearch; 
    int iBinarySearchResult;

    printf("Enter the size of array     : ");
    scanf("%d", &iSizeOfArray);
    sortArray(iaArray, iSizeOfArray);
    for (int i = 0; i < iSizeOfArray; i++)
    {
        printf("%d  ", iaArray[i]);
    }
    

    printf("Enter the value to search   : ");
    scanf("%d", &iValueToSearch);
    iBinarySearchResult = binarySearch(iaArray, iSizeOfArray, iValueToSearch);

    if (iBinarySearchResult == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at %d index\n", iBinarySearchResult);
    }
}

int binarySearch(int iaArray[], int iSizeOfArray, int iValueToSearch)
{
    int iStartIndex = 0;
    int iEndIndex = iSizeOfArray - 1;
    int iMidIndex;

    while (iStartIndex <= iEndIndex)
    {
        iMidIndex = (iStartIndex + iEndIndex) / 2;

        if (iaArray[iMidIndex] == iValueToSearch)
        {
            return iMidIndex;
        }
        else if (iValueToSearch > iaArray[iMidIndex])
        {
            iStartIndex = iMidIndex + 1;
        }
        else if (iValueToSearch < iaArray[iMidIndex])
        {
            iEndIndex = iMidIndex - 1; 
        }
        //
    }
    return -1;    
}

void sortArray(int iaArray[], int iSizeOfArray)
{
    int iIndexI;
    int iIndexJ;
    int iTemp;

    for(iIndexI = 0; iIndexI < iSizeOfArray; iIndexI++)
    {
        for(iIndexJ = 0; iIndexJ < iSizeOfArray; iIndexJ++)
        {
            if(iaArray[iIndexJ] > iaArray[iIndexJ + 1])
            {
                iTemp = iaArray[iIndexJ];
                iaArray[iIndexJ] = iaArray[iIndexJ+1];
                iaArray[iIndexJ+1] = iTemp;
            }
        }
    }
}
