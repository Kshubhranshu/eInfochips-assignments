/*
9. Write a C program which prints itself.
*/
#include<stdio.h>

void main() 
{ 
    FILE *pFilePointer;
    char chCharacter;

    /*stores the base address of the file*/
    pFilePointer = fopen(__FILE__, "r");

    /*checks if file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("File failed to open!!!\n");
    }
    else
    {   
        
        /*reads each character from the file and prints it on the console*/
        printf("File opened successfully \xE2\x9C\x93 \n\n");
        printf("\n---Source code starts---\n\n");
        do
        {
        chCharacter= fgetc(pFilePointer);

        /**/
        if(chCharacter == EOF)
        {
            break;
        }

        putchar(chCharacter);
        } while (chCharacter != EOF);
        printf("\n\n");
    }
    printf("---Source code ends---\n\n\n");

    /*closing file*/
    fclose(pFilePointer);
    printf("File closed successfully \xE2\x9C\x93 \n\n");
}  