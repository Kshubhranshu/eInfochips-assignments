#include <stdio.h>
#include <stdlib.h>

int largestElementIndex(int iaArray[], int iSizeOfArray); 


void main()
{
    FILE *FilePointer;
    int iCharactersCountBuffer[10] = {0};
    char chCopyCharacter;
    char chCharacters;
    int iIndex = 0;
    int iNoOfLines = 0;
    int iCursorPosition;
    int iCharactersCountSum = 0;
    int iIndexForCharacterCountSum;

    FilePointer = fopen("file1.txt", "r");

    if(FilePointer == NULL)
    {
        printf("File doesnot exists!\n");
        exit(0);
    }

    while((chCharacters = fgetc(FilePointer)) != EOF)
    {   
        iCharactersCountBuffer[iIndex]++;
        if(chCharacters == '\n')
        {
            iIndex++;
            iNoOfLines++;
        }
    }

    iNoOfLines = iNoOfLines + 1;
    iCursorPosition = largestElementIndex(iCharactersCountBuffer, iNoOfLines);

    for(iIndexForCharacterCountSum = 0; iIndexForCharacterCountSum < iCursorPosition; iIndexForCharacterCountSum++)
    {
        iCharactersCountSum += iCharactersCountBuffer[iIndexForCharacterCountSum];
    }

    printf("Longest line is line no. %d and its count is %d\n", iCursorPosition, iCharactersCountBuffer[iCursorPosition]);
    
    fseek(FilePointer, iCharactersCountSum, SEEK_SET);
    while((chCopyCharacter = fgetc(FilePointer)) != EOF)
    {   
        if(chCopyCharacter == '\n')
        {
            break;
        }
        printf("%c", chCopyCharacter);
    }
    printf("\n");






}

int largestElementIndex(int iaArray[], int iSizeOfArray) 
{ 
    int iIndex; 
    int iIndexOfLargestElement = 0;
    int iMax = iaArray[0];
    for (iIndex = 1; iIndex < iSizeOfArray; iIndex++)
    {
        if (iaArray[iIndex] > iMax)
        {
            iMax = iaArray[iIndex];
            iIndexOfLargestElement = iIndex;
        }
    }
    return iIndexOfLargestElement; 
} 

