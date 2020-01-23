/*Program to create a new file and write in it*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *pFilePointer;    //    holds the address of file
    int iCharacter;     //stores each character from file

    /*stores the address of the file opened*/
    pFilePointer = fopen("new.txt", "w");

    /*checks whether file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("Cannot open file!\n");
        exit(0);
    }

    /*copies the data into the file*/
    fputs("hello this is new file data\n", pFilePointer);    
}