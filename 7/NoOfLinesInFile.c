/*Program to count no of lines in a file*/
#include <stdio.h>
#include <stdlib.h>

char *achFileName = "file1.txt";

/*
    * this methods shows the file usage details
    *
    * @return void
*/
void getFileUsage();

void main()
{
    FILE *pFilePointer;  //holds the address of file//
    int iCharacter;     //stores each character from file
    int iNoOfLinesCounter = 0;

    /*file usage information*/
    getFileUsage();

    /*stores the address of file opened*/
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

    /*counts the no of lines in a file*/
    while((iCharacter = fgetc(pFilePointer)) != EOF)
    {   
        if(iCharacter == '\n')
        {
            iNoOfLinesCounter++;
        }
    }

    /*prints the no of lines in a file*/
    printf("No of lines in file : %d\n\n", (iNoOfLinesCounter + 1));
    


    /*closing file*/
    fclose(pFilePointer);
    printf("File closed successfully \xE2\x9C\x93 \n");
}

void getFileUsage()
{
    printf("File Usage\n");
    printf("Input filename          : %s\n", achFileName);
    printf("File directory          : home/einfochips/Desktop/eInfochips-tasks-master/7\n");
    printf("\n");
}