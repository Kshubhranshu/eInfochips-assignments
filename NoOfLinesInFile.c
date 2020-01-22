#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *pFilePointer;  /*holds the address of file*/
    int iCharacter;     /*stores each character from file*/
    int iNoOfLinesCounter = 0;
    pFilePointer = fopen("file1.txt", "r");

    while((iCharacter = fgetc(pFilePointer)) != EOF)
    {   
        if(iCharacter == '\n')
        {
            iNoOfLinesCounter++;
        }
        //
    }

    if(iCharacter == -1)
    {
        printf("No of lines : %d\n", (iNoOfLinesCounter));
    }
    else
    {
        printf("No of lines : %d\n", (iNoOfLinesCounter + 1));        
    }
}