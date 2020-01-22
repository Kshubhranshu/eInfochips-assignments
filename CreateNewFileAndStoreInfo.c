#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *pFilePointer;  /*holds the address of file*/
    int iCharacter;     /*stores each character from file*/

    pFilePointer = fopen("new.txt", "w");
    fputs("hello this is new file data\n", pFilePointer);    
}