/*Program to create a new file and write in it*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define N 1000

char achFileName[] = "new.txt";     // buffer for file name
/*
    * this methods shows the file usage details
    *
    * @return void
*/
void getFileUsage();

void main()
{
    FILE *pFilePointer;    //    holds the address of file
    char chChoice;
    char achDataBuffer[N];


    /*file usage information*/
    getFileUsage();

    /*validate if the file with same name already exist*/
    if( access(achFileName , F_OK ) != -1 )
    {
        printf("A file named \"%s\" already exists.  Do you want to replace it?[y/n] : ", achFileName);
        scanf("%c", &chChoice);
        if(chChoice != 'y')
        {
            exit(0);
        }
        printf("\n");
    }

    /*stores the address of the file opened*/
    pFilePointer = fopen(achFileName, "w");

    /*checks whether file exists or not*/
    if(pFilePointer == NULL)
    {
        printf("Cannot open file!\n");
        exit(0);
    }
    else
    {
        printf("File created successfully \xE2\x9C\x93 \n\n");
    }

    /*input the data into the data buffer*/
    printf("---------------------------Start Writing[\x1b[33;50mmax char capacity: %d\x1b[m][\x1b[31;25m press \x1b[33;50mTab Enter\x1b[m \x1b[31;25mto end writing \x1b[m]---------------------------\n", N);
    scanf("%[^\t]", achDataBuffer);
    printf("---------------------------------------------------------------End------------------------------------------------------------\n");

    /*validate input*/
    if(strlen(achDataBuffer) > (N - 1))
    {
        printf("\x1b[31;40mOops! Maximum capacity exceeded!!\x1b[m\n");
        exit(0);
    }

    /*copy data from buffer to file*/
    fputs(achDataBuffer, pFilePointer);
    printf("Data written successfully \xE2\x9C\x93 \n\n");

    /*closing file*/
    fclose(pFilePointer);
    printf("File closed successfully \xE2\x9C\x93 \n\n");
    
}

void getFileUsage()
{
    printf("File Usage\n");
    printf("Filename                                               : %s\n", achFileName);
    printf("File directory                                         : home/einfochips/Desktop/eInfochips-tasks-master/7\n");
    printf("\n");
}