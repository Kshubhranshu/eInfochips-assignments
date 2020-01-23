#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *pSourceFile;  
    FILE *pDestinationFile;
    int iCharacter;
    
    /*stores the address of the file opened*/
    pSourceFile = fopen("file1.txt", "r");
    
    /*checks if file exists or not*/
    if (pSourceFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    /*stores the address of the file opened*/
    pDestinationFile = fopen("file2.txt", "w");
    
    /*checks if file exists or not*/
    if (pDestinationFile == NULL)
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