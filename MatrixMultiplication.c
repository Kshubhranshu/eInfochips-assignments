/*Program to perform matrix multiplication for matrix nxn*/
#include <stdio.h>
#include <stdlib.h>
#define N 100  // maximum size of columns of the matrices

/*
    * multiplies the two matrices aiMatrixA and aiMatrixB and stores the resultant in the matrix aiResultantMatrix
    *
    * @param aiMatrixA is the first matrix of dimension nxn
    *
    * @param aiMatrixB is the second matrix of dimension nxn
    *
    * @param aiResultantMatrix is the third matrix of dimension nxn
    *
    * @param iNoOfColumns is the number of columns of the matrix
    *
    * @param iNoOfRows is the number of rows of the matrix
    *
    * @return void
*/
void getMatrixMultiplication(int aiMatrixA[][N], int aiMatrixB[][N], int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);

/*
* prints the resultant matrix
*
* @param aiResutantMatrix is the resultant matrix
*
* @param iNoOfColumns is the no of columns of the resultant matrix
*
* @param iNoOfRows is the no of rows of the resultant matrix
*
* @return void
*/
void getResultantMatrix(int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);

/*
* takes user input for matrix data
*
* @param aiMatrix
*
* @param iNoOfColumns is the no of columns of the matrix
*
* @param iNoOfRows is the no of rows of the matrix
*
* @return void
*/
void getInput(int aiMatrix[][N], int *pNoOfColumns, int *pNoOfRows);



void main()
{
    int iNoOfRows;
    int iNoOfColumns;
    int aiMatrixA[N][N];
    int aiMatrixB[N][N];
    int aiResultantMatrix[N][N];


    printf("**constraint : [nxn] matrix**\n");

    /*input rows*/
    printf("Enter no of rows    : ");
    scanf("%d", &iNoOfRows);

    /*input columns*/
    printf("Enter no of columns : ");
    scanf("%d", &iNoOfColumns);

    printf("\n");

    /*validate matrix*/
    if((0 == iNoOfRows) && (0 == iNoOfColumns) || (iNoOfColumns != iNoOfRows))
    {   
        printf("Invalid inputs dimensions cannot be %dx%d refer constraints!!!\n", iNoOfRows, iNoOfColumns);
        exit(0);
    }

    /*matrixA input*/
    printf("Enter into MatrixA\n");
    getInput(aiMatrixA, &iNoOfColumns, &iNoOfRows);

    /*prints matrix A*/
    printf("Matrix A [%dx%d]\n", iNoOfRows, iNoOfColumns);
    getResultantMatrix(aiMatrixA, iNoOfColumns, iNoOfRows);
    printf("\n");
    
    /*matrixA input*/
    printf("Enter into MatrixB\n");
    getInput(aiMatrixB, &iNoOfColumns, &iNoOfRows);

    /*prints matrix B*/
    printf("Matrix B [%dx%d]\n", iNoOfRows, iNoOfColumns);
    getResultantMatrix(aiMatrixB, iNoOfColumns, iNoOfRows);
    printf("\n");

    /*calculates the matrix multiplication*/
    printf("Resultant Matrix [%dx%d]\n", iNoOfRows, iNoOfColumns);
    getMatrixMultiplication(aiMatrixA, aiMatrixB,aiResultantMatrix, iNoOfColumns, iNoOfRows);

    /*prints the resultant matrix*/
    getResultantMatrix(aiResultantMatrix, iNoOfColumns, iNoOfRows);

}

void getMatrixMultiplication(int aiMatrixA[][N], int aiMatrixB[][N], int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows)
{
    int iColumnIndex;
    int iRowIndex;
    int iIndex;

    for(iRowIndex = 0; iRowIndex < iNoOfRows; iRowIndex++)
    {
        for(iColumnIndex = 0; iColumnIndex < iNoOfColumns; iColumnIndex++)
        {
            aiResultantMatrix[iRowIndex][iColumnIndex] = 0;
            for(iIndex = 0; iIndex <  iNoOfRows; iIndex++)
            {
                aiResultantMatrix[iRowIndex][iColumnIndex] += aiMatrixA[iRowIndex][iIndex] * aiMatrixB[iIndex][iColumnIndex]; 
            }   
        }
    }
    
}

void getResultantMatrix(int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows)
{
    int iRowIndex;
    int iColIndex;

    for(iRowIndex = 0; iRowIndex < iNoOfRows; iRowIndex++)
    {
        for(iColIndex = 0; iColIndex < iNoOfColumns; iColIndex++)
        {
            printf("%d    ", aiResultantMatrix[iRowIndex][iColIndex]);
        }

        printf("\n");
    }
}

void getInput(int aiMatrix[][N], int *pNoOfColumns, int *pNoOfRows)
{

    int iRowIndex;
    int iColumnIndex;
    int iNoOfRows;
    int iNoOfColumns;

    iNoOfRows = (*pNoOfRows);
    iNoOfColumns = (*pNoOfColumns);
    
    /*input matrix*/
    for(iRowIndex = 0; iRowIndex < iNoOfRows; iRowIndex++)
    {
        for(iColumnIndex = 0; iColumnIndex < iNoOfColumns; iColumnIndex++)
        {
            scanf("%d", &aiMatrix[iRowIndex][iColumnIndex]);
        }
    }
    
}
