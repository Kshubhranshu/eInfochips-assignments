#include<stdio.h>
#define N 3
void getMatrixMultiplication(int iaMatrixA[][N], int iaMatrixB[][N], int iaResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);
void getResultantMatrix(int iaResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);

void main()
{
    int iaMatrixA[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int iaMatrixB[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int iaResultantMatrix[N][N];
    int iNoOfRows = N;
    int iNoOfColumns = N;
    getMatrixMultiplication(iaMatrixA, iaMatrixB,iaResultantMatrix, iNoOfColumns, iNoOfRows);
    getResultantMatrix(iaResultantMatrix, iNoOfColumns, iNoOfRows);

}

void getMatrixMultiplication(int iaMatrixA[][N], int iaMatrixB[][N], int iaResultantMatrix[][N], int iNoOfColumns, int iNoOfRows)
{
    int iColumnIndex;
    int iRowIndex;
    int iIndex;

    for(iRowIndex = 0; iRowIndex < iNoOfRows; iRowIndex++)
    {
        for(iColumnIndex = 0; iColumnIndex < iNoOfColumns; iColumnIndex++)
        {
            iaResultantMatrix[iRowIndex][iColumnIndex] = 0;
            for(iIndex = 0; iIndex <  iNoOfRows; iIndex++)
            {
                iaResultantMatrix[iRowIndex][iColumnIndex] += iaMatrixA[iRowIndex][iIndex] * iaMatrixB[iIndex][iColumnIndex]; 
            }   
        }
    }
    
}

void getResultantMatrix(int iaResultantMatrix[][N], int iNoOfColumns, int iNoOfRows)
{
    int iRowIndex;
    int iColIndex;

    for(iRowIndex = 0; iRowIndex < iNoOfRows; iRowIndex++)
    {
        for(iColIndex = 0; iColIndex < iNoOfColumns; iColIndex++)
        {
            printf("%d    ", iaResultantMatrix[iRowIndex][iColIndex]);
        }
        printf("\n");
    }
}

