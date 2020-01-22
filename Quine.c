#include<stdio.h>

void main() 
{ 
    /*
    * THIS IS QUINE PROGRAM
    * char *s="main() { char *s=%c%s%c; printf(s,34,s,34); }";
    * printf(s,34,s,34);
    */
   
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