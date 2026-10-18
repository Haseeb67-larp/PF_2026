#include<stdio.h>
int main() {
    int inputMatrix[3][3], transposeMatrix[3][3], cofactorMatrix[3][3], adjointMatrix[3][3];
    double inverseMatrix[3][3];
    int subMinor[2][2], determinant = 0;
    int row, col, subRow, subCol, minorRow, minorCol;

    printf("Enter the elements of the 3x3 matrix:\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("inputMatrix[%d][%d] = ", row + 1, col + 1);
            scanf("%d", &inputMatrix[row][col]);
        }
    }

    printf("\n===== STAGE 1: ORIGINAL MATRIX =====\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("%6d ", inputMatrix[row][col]);
        }
        printf("\n");
    }

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            transposeMatrix[col][row] = inputMatrix[row][col];
        }
    }

    printf("\n===== STAGE 2: TRANSPOSE =====\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("%6d ", transposeMatrix[row][col]);
        }
        printf("\n");
    }

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            minorRow = 0;
            for (subRow = 0; subRow < 3; subRow++) {
                if (subRow == row) continue;
                minorCol = 0;
                for (subCol = 0; subCol < 3; subCol++) {
                    if (subCol == col) continue;
                    subMinor[minorRow][minorCol] = inputMatrix[subRow][subCol];
                    minorCol++;
                }
                minorRow++;
            }
            int minorValue = subMinor[0][0] * subMinor[1][1] - subMinor[0][1] * subMinor[1][0];
            cofactorMatrix[row][col] = ((row + col) % 2 == 0) ? minorValue : -minorValue;
        }
    }

    printf("\n===== STAGE 3: COFACTOR MATRIX =====\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("%6d ", cofactorMatrix[row][col]);
        }
        printf("\n");
    }

    for (col = 0; col < 3; col++) {
        determinant += inputMatrix[0][col] * cofactorMatrix[0][col];
    }

    printf("\n===== STAGE 4: DETERMINANT =====\n");
    printf("det(A) = %d\n", determinant);

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            adjointMatrix[col][row] = cofactorMatrix[row][col];
        }
    }

    printf("\n===== STAGE 5: ADJOINT =====\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("%6d ", adjointMatrix[row][col]);
        }
        printf("\n");
    }

    printf("\n===== STAGE 6: INVERSE =====\n");
    if (determinant == 0) {
        printf("Matrix is singular (det = 0). Inverse does not exist.\n");
    } else {
        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                inverseMatrix[row][col] = (double)adjointMatrix[row][col] / determinant;
            }
        }
        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                printf("%9.4f ", inverseMatrix[row][col]);
            }
            printf("\n");
        }
    }
    return 0;
}
