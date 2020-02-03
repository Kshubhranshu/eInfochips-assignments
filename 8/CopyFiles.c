/*Program to copy the data of one file to the other one*/
#include<stdio.h>
#include<stdlib.h>

/*
    * this methods shows the file usage details
    *
    * @return void
*/
void getFileUsage(char achSourceFile[], char achDestinationFile[]);

void main()
{
    FILE *pSourceFile; 
    FILE *pDestinationFile;
    int iCharacter;     // to copy characters from source file to destination
    char *achSourceFileName = "file1.txt";
    char *achDestinationFileName = "file2.txt";

    /*file usage information*/
    getFileUsage(achSourceFileName, achDestinationFileName);

    /*stores the address of the file opened*/
    pSourceFile = fopen(achSourceFileName, "r");
    
    /*checks if file exists or not*/
    if (NULL == pSourceFile)
    {
        printf("File failed to open!!\n");
        exit(0);
    }
    else
    {
        printf("Source file opened successfully \xE2\x9C\x93\n\n");
    }

    /*stores the address of the file opened*/
    pDestinationFile = fopen(achDestinationFileName, "w");
    
    /*checks if file exists or not*/
    if (NULL == pDestinationFile)
    {
        printf("File failed to open\n");
        exit(0);
    }
    else
    {
        printf("Destination file opened successfully \xE2\x9C\x93 \n\n");
    }

    /*reading data from file using fgetc*/
    while((iCharacter = fgetc(pSourceFile)) != EOF)
    {
        fputc(iCharacter, pDestinationFile);
    }
    printf("Data copied successfully \xE2\x9C\x93 \n\n");

    /*closing the file*/
    fclose(pSourceFile);
    printf("Source file closed successfully \xE2\x9C\x93 \n\n");

    fclose(pDestinationFile);
    printf("Destination file closed successfully \xE2\x9C\x93 \n\n");
}

void getFileUsage(char achSourceFileName[], char achDestinationFileName[])
{
    printf("File Usage\n");
    printf("Source filename                                       : %s\n", achSourceFileName);
    printf("Destination filename[\x1b[31;23mall previous data will be erased\x1b[m]: %s\n", achDestinationFileName);
    printf("File directory                                        : home/einfochips/Desktop/eInfochips-tasks-master/8\n");
    printf("\n");
}
