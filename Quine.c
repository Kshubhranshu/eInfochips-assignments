#include<stdio.h>

void main() 
{ 
    /*
    * THIS IS QUINE PROGRAM
    * char *s="main() { char *s=%c%s%c; printf(s,34,s,34); }";
    * printf(s,34,s,34);
    */
   
    FILE *FilePointer;
    char chCharchter;

    FilePointer = fopen(__FILE__, "r");
    if(FilePointer == NULL)
    {
        printf("File not opened successfully\n");
    }
    else
    {
        do
        {
        chCharchter = fgetc(FilePointer);
        putchar(chCharchter);
        } while (chCharchter != EOF);
    }
    fclose(FilePointer);
}  