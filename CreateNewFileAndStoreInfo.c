#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *FilePointer;  /*holds the address of file*/
    int iCharacter;     /*stores each character from file*/

    FilePointer = fopen("new.txt", "w");
    fputs("hello this is new file data\n", FilePointer);    
}