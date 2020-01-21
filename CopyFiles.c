#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *SourceFile;
    FILE *DestinationFile;
    int iCharacter;
    
    SourceFile = fopen("file1.txt", "r");
    if (SourceFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    DestinationFile = fopen("file2.txt", "w");
    if (DestinationFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    while((iCharacter = fgetc(SourceFile)) != EOF)
    {
        fputc(iCharacter, DestinationFile);
        //
    }
    fclose(SourceFile);
    fclose(DestinationFile);
}