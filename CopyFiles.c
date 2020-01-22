#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *pSourceFile;
    FILE *pDestinationFile;
    int iCharacter;
    
    pSourceFile = fopen("file1.txt", "r");
    if (pSourceFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    pDestinationFile = fopen("file2.txt", "w");
    if (pDestinationFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    while((iCharacter = fgetc(pSourceFile)) != EOF)
    {
        fputc(iCharacter, pDestinationFile);
        //
    }
    fclose(pSourceFile);
    fclose(pDestinationFile);
}