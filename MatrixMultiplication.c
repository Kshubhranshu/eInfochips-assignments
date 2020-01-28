/*Program to perform matrix multiplication*/
#include<stdio.h>
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

void main()
{
    int aiMatrixA[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int aiMatrixB[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int aiResultantMatrix[N][N];
    int iNoOfRows = N;
    int iNoOfColumns = N;

    /*calculates the matrix multiplication*/
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

