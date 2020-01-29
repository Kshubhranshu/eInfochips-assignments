/*Program to copy the data of one file to the other one*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *pSourceFile;  
    FILE *pDestinationFile;
    int iCharacter;     // to copy characters from source file to destination
    
    /*stores the address of the file opened*/
    pSourceFile = fopen("file1.txt", "r");
    
    /*checks if file exists or not*/
    if (NULL == pSourceFile)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    /*stores the address of the file opened*/
    pDestinationFile = fopen("file2.txt", "w");
    
    /*checks if file exists or not*/
    if (NULL == pDestinationFile)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    /*reading data from file using fgetc*/
    while((iCharacter = fgetc(pSourceFile)) != EOF)
    {
        fputc(iCharacter, pDestinationFile);
    }

    /*closing the file*/
    fclose(pSourceFile);
    fclose(pDestinationFile);
}