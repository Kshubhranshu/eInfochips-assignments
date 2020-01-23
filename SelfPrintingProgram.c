/*Program that prints itself*/
#include<stdio.h>

void main() 
{ 
    FILE *pFilePointer;
    char chCharchter;

    /*stores the base address of the file*/
    pFilePointer = fopen(__FILE__, "r");

    /*checks if file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("File not opened successfully\n");
    }
    else
    {   
        
        /*reads each character from the file and prints it on the console*/
        do
        {
        chCharchter = fgetc(pFilePointer);
        putchar(chCharchter);
        } while (chCharchter != EOF);
    }

    /*closing the file*/
    fclose(pFilePointer);
}  