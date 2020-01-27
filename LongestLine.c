/*Program to find the longest line in a file*/
#include <stdio.h>
#include <stdlib.h>

/*
    * this methods finds the line number with maximum characters
    *
    * @param aiArray[] is the actual array which stores the charactes count of each line
    *
    * @param iSizeOfArray stores the total number of lines in the file
    *
    * @return returns the line number with maximum characters count
*/
int largestElementIndex(int aiArray[], int iSizeOfArray); 

void main()
{
    FILE *pFilePointer; 
    int aiCharactersCountBuffer[100];    
    int iLineCount = 0;             // counts the total no of lines in the file
    char *pLineData;                //  stores each line data to count no of characters
    size_t iLengthOfEachLine = 0;   //  stores the length of each line
    int iMaxCharactersLineNumber;   //  stores the line number with maximum characters count
    int iOffsetValue = 0;           
    int iIndex;     // for iterating over the characters count buffer

    /*stores the address of the file opened*/
    pFilePointer = fopen("file1.txt", "r");

    /*checks whether file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("File doesnot exists!\n");
        exit(0);
    }

    /*counting no of characters per line and storing in aiCharactersCountBuffer*/
    while ((aiCharactersCountBuffer[iLineCount++] = getline(&pLineData, &iLengthOfEachLine, pFilePointer)) != -1);

    /*stores the line number having max characters count*/
    iMaxCharactersLineNumber = largestElementIndex(aiCharactersCountBuffer, iLineCount);

    /*counting the offset value from SEEK_SET*/
    for(iIndex = 0; iIndex < iMaxCharactersLineNumber; iIndex++)
    {
         iOffsetValue += aiCharactersCountBuffer[iIndex];
    } 
    
    /*prints the line no and no of characters*/
    printf("Longest line is line no. %d and its count is %d\n", (iMaxCharactersLineNumber + 1), aiCharactersCountBuffer[iMaxCharactersLineNumber]);
     
    /*sets the cursor to the starting of the line having max characters*/
    fseek(pFilePointer, iOffsetValue, SEEK_SET);

    /*prints the line having max characters*/
    fgets(pLineData, 256, pFilePointer) != NULL;
    printf("%s\n", pLineData);

    /*closing file*/
    fclose(pFilePointer);
}

int largestElementIndex(int aiArray[], int iSizeOfArray) 
{ 
    int iIndex; 
    int iIndexOfLargestElement = 0;
    int iMax = aiArray[0];

    for (iIndex = 1; iIndex < iSizeOfArray; iIndex++)
    {
        if (aiArray[iIndex] > iMax)
        {
            iMax = aiArray[iIndex];
            iIndexOfLargestElement = iIndex;
        }
    }

    return iIndexOfLargestElement; 
} 

