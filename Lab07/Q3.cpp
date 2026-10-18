#include<stdio.h>
int main()
{
    int matrixA[3][3], matrixB[3][3], resultMatrix[3][3];
    int rowsA, colsA, rowsB, colsB;
    int rowIdx, colIdx, innerProductIdx;

    printf("Rows and columns of A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Rows and columns of B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA > 3 || colsA > 3 || rowsB > 3 || colsB > 3 || colsA != rowsB) {
        printf("Multiplication not possible.\n");
        return 1;
    }

    printf("Enter A:\n");
    for (rowIdx = 0; rowIdx < rowsA; rowIdx++) {
        for (colIdx = 0; colIdx < colsA; colIdx++) {
            scanf("%d", &matrixA[rowIdx][colIdx]);
        }
    }

    printf("Enter B:\n");
    for (rowIdx = 0; rowIdx < rowsB; rowIdx++) {
        for (colIdx = 0; colIdx < colsB; colIdx++) {
            scanf("%d", &matrixB[rowIdx][colIdx]);
        }
    }

    for (rowIdx = 0; rowIdx < rowsA; rowIdx++) {
        for (colIdx = 0; colIdx < colsB; colIdx++) {
            resultMatrix[rowIdx][colIdx] = 0;
            for (innerProductIdx = 0; innerProductIdx < colsA; innerProductIdx++) {
                resultMatrix[rowIdx][colIdx] += matrixA[rowIdx][innerProductIdx] * matrixB[innerProductIdx][colIdx];
            }
        }
    }

    printf("\nA:\n");
    for (rowIdx = 0; rowIdx < rowsA; rowIdx++) {
        for (colIdx = 0; colIdx < colsA; colIdx++) {
            printf("%5d", matrixA[rowIdx][colIdx]);
        }
        printf("\n");
    }

    printf("\nB:\n");
    for (rowIdx = 0; rowIdx < rowsB; rowIdx++) {
        for (colIdx = 0; colIdx < colsB; colIdx++) {
            printf("%5d", matrixB[rowIdx][colIdx]);
        }
        printf("\n");
    }

    printf("\nA x B:\n");
    for (rowIdx = 0; rowIdx < rowsA; rowIdx++) {
        for (colIdx = 0; colIdx < colsB; colIdx++) {
            printf("%5d", resultMatrix[rowIdx][colIdx]);
        }
        printf("\n");
    }
    return 0;
}
