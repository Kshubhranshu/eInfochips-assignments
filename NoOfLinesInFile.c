#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *pFilePointer;  /*holds the address of file*/
    int iCharacter;     /*stores each character from file*/
    int iNoOfLinesCounter = 0;

    /*stores the address of file opened*/
    pFilePointer = fopen("file1.txt", "r");

    /*counts the no of lines in a file*/
    while((iCharacter = fgetc(pFilePointer)) != EOF)
    {   
        if(iCharacter == '\n')
        {
            iNoOfLinesCounter++;
        }
    }

    /*prints the no of lines in a file*/
    if(iCharacter == -1)
    {
        printf("No of lines : %d\n", (iNoOfLinesCounter));
    }
    else
    {
        printf("No of lines : %d\n", (iNoOfLinesCounter + 1));        
    }
}