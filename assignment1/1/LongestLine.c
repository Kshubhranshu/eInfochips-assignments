/*
1. Write a program to find and print the longest line for a fixedinput set of 10 lines having a max of 256 characters in a line.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10   // maximum array limit
#define MAXC 256 // maximum characters per line

char *achFileName = "file1.txt";


/*
    * this methods finds the line number with maximum characters
    *
    * @param aiArray[] is the actual array which stores the charactes count of each line
    *
    * @param iSizeOfArray stores the total number of lines in the file
    *
    * @return int
*/
int largestElementIndex(int aiArray[], int iSizeOfArray);

/*
    * this methods shows the file usage details
    *
    * @return void
*/
void getFileUsage();

void main()
{
    FILE *pFilePointer; 
    int aiCharactersCountBuffer[N] = {0};    
    int iLineCount = 0;             // counts the total no of lines in the file
    char *pLineData;                //  stores each line data to count no of characters
    size_t iLengthOfEachLine = 0;   //  stores the length of each line
    int iMaxCharactersLineNumber;   //  stores the line number with maximum characters count
    int iOffsetValue = 0;           
    int iIndex;                     // for iterating over the characters count buffer

    /*file usage information*/
    getFileUsage();

    /*stores the address of the file opened*/
    pFilePointer = fopen(achFileName, "r");

    /*checks whether file exists or not*/
    if(NULL == pFilePointer)
    {
        printf("File doesnot exists!\n");
        exit(0);
    }
    else
    {
        printf("File opened successfully \xE2\x9C\x93 \n\n");
    }

    /*counting no of characters per line and storing in aiCharactersCountBuffer*/
    while ((aiCharactersCountBuffer[iLineCount] = getline(&pLineData, &iLengthOfEachLine, pFilePointer)) != -1)
    {
        /*validation check for 256 max characters perline*/
        if(aiCharactersCountBuffer[iLineCount] > (MAXC - 1))
        {
            printf("Max characters limit exceeded [MaxLimit: %d]\n", MAXC);
            exit(0);
        }
        
        iLineCount++;
    };
    
    

    /*validation for line number maximum limit*/
    if(iLineCount > (N - 1))

    {
        printf("Maximum line limit exceeded!!!\n");
        exit(0);
    }

    /*stores the line number having max characters count*/
    iMaxCharactersLineNumber = largestElementIndex(aiCharactersCountBuffer, iLineCount);

    /*counting the offset value from SEEK_SET*/
    for(iIndex = 0; iIndex < iMaxCharactersLineNumber; iIndex++)
    {
         iOffsetValue += aiCharactersCountBuffer[iIndex];
    } 
    
    /*prints the line no and no of characters*/
    if(aiCharactersCountBuffer[0] == -1)
    {
        /*if file is empty*/
        printf("Longest line is line no. %d and its count is %d\n", (iMaxCharactersLineNumber + 1), aiCharactersCountBuffer[iMaxCharactersLineNumber]+1);
    }
    else
    {
        printf("Longest line is line no. %d and its count is %d\n", (iMaxCharactersLineNumber + 1), aiCharactersCountBuffer[iMaxCharactersLineNumber]);
    }
    
     
    /*sets the cursor to the starting of the line having max characters*/
    fseek(pFilePointer, iOffsetValue, SEEK_SET);

    /*prints the line having max characters*/
    fgets(pLineData, MAXC, pFilePointer) != NULL;
    printf("Data: %s\n", pLineData);

    /*closing file*/
    fclose(pFilePointer);
    printf("File closed successfully \xE2\x9C\x93 \n\n");

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

void getFileUsage()
{
    printf("File Usage\n");
    printf("Max lines limit         : %d\n", N);
    printf("Max characters per line : %d\n", MAXC   );
    printf("Input filename          : %s\n", achFileName);
    printf("File directory          : home/einfochips/Desktop/eInfochips-tasks-master/1\n");
    printf("\n");
}

