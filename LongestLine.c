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
    int iCharactersCountBuffer[10] = {0};
    char chCopyCharacter;
    char chCharacters;
    int iIndex = 0;
    int iNoOfLines = 0;
    int iCursorPosition;
    int iCharactersCountSum = 0;
    int iIndexForCharacterCountSum;

    /*stores the address of the file opened*/
    pFilePointer = fopen("file1.txt", "r");

    /*checks whether file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("File doesnot exists!\n");
        exit(0);
    }

    /*reading data from file using fgetc*/
    while((chCharacters = fgetc(pFilePointer)) != EOF)
    {   
        iCharactersCountBuffer[iIndex]++;

        /*counts the no of lines in the file*/
        if(chCharacters == '\n')
        {
            iIndex++;
            iNoOfLines++;
        }
    }

    iNoOfLines = iNoOfLines + 1;

    /*stores the line no having max characters*/
    iCursorPosition = largestElementIndex(iCharactersCountBuffer, iNoOfLines);

    /*counts the no of characters occuring before the line with highest characters*/
    for(iIndexForCharacterCountSum = 0; iIndexForCharacterCountSum < iCursorPosition; iIndexForCharacterCountSum++)
    {
        iCharactersCountSum += iCharactersCountBuffer[iIndexForCharacterCountSum];
    }

    /*prints the line no and no of characters*/
    printf("Longest line is line no. %d and its count is %d\n", iCursorPosition, iCharactersCountBuffer[iCursorPosition]);
    
    /*prints the line*/
    fseek(pFilePointer, iCharactersCountSum, SEEK_SET);
    while((chCopyCharacter = fgetc(pFilePointer)) != EOF)
    {   
        if(chCopyCharacter == '\n')
        {
            break;
        }
        printf("%c", chCopyCharacter);
    }

    printf("\n");
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

