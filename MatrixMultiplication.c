#include<stdio.h>
#define N 3  //number of columns
void getMatrixMultiplication(int aiMatrixA[][N], int aiMatrixB[][N], int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);
void getResultantMatrix(int aiResultantMatrix[][N], int iNoOfColumns, int iNoOfRows);

void main()
{
    int aiMatrixA[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int aiMatrixB[N][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int aiResultantMatrix[N][N];
    int iNoOfRows = N;
    int iNoOfColumns = N;
    getMatrixMultiplication(aiMatrixA, aiMatrixB,aiResultantMatrix, iNoOfColumns, iNoOfRows);
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

