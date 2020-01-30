/*Program to copy the data of one file to the other one*/
#include<stdio.h>
#include<stdlib.h>


/*
    * this methods shows the file usage details
    *
    * @return void
*/
void getFileUsage();

void main()
{
    FILE *pSourceFile; 
    FILE *pDestinationFile;
    int iCharacter;     // to copy characters from source file to destination

    /*file usage information*/
    getFileUsage();

    /*stores the address of the file opened*/
    pSourceFile = fopen("file1.txt", "r");
    
    /*checks if file exists or not*/
    if (NULL == pSourceFile)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    else
    {
        printf("Source file opened successfully \xE2\x9C\x93\n\n");
    }

    /*stores the address of the file opened*/
    pDestinationFile = fopen("file2.txt", "w");
    
    /*checks if file exists or not*/
    if (NULL == pDestinationFile)
    {
        printf("Cannot open file\n");
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

void getFileUsage()
{
    printf("File Usage\n");
    printf("Source filename                                       : file1.txt\n");
    printf("Destination filename[\x1b[31;23mall previous data will be erased\x1b[m]: file2.txt\n");
    printf("File directory                                        : home/einfochips/Desktop/eInfochips-tasks-master\n");
    printf("\n");
}
