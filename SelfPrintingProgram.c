#include<stdio.h>

void main() 
{ 
    FILE *pFilePointer;
    char chCharchter;

    pFilePointer = fopen(__FILE__, "r");

    if(pFilePointer == NULL)
    {
        printf("File not opened successfully\n");
    }
    else
    {
        do
        {
        chCharchter = fgetc(pFilePointer);
        putchar(chCharchter);
        } while (chCharchter != EOF);
    }

    fclose(pFilePointer);
}  