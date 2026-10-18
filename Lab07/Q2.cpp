#include<stdio.h>
int main()
{
    int primaryMatrix[5][5], secondaryMatrix[5][5];
    int primaryRows, primaryCols, secondaryRows, secondaryCols;
    int rowIdx, colIdx;
    
    int isSquare, isZero, isDiagonal, isScalar, isIdentity, isUpperTriangular, isLowerTriangular;
    int isSymmetric, isSkewSymmetric, isEqual;
    char userChoice;

    printf("Enter number of rows (1-5): ");
    scanf("%d", &primaryRows);
    printf("Enter number of columns (1-5): ");
    scanf("%d", &primaryCols);

    if (primaryRows < 1 || primaryRows > 5 || primaryCols < 1 || primaryCols > 5) {
        printf("Invalid size! Rows and columns must be between 1 and 5.\n");
        return 1;
    }

    printf("\nEnter the matrix elements:\n");
    for (rowIdx = 0; rowIdx < primaryRows; rowIdx++) {
        for (colIdx = 0; colIdx < primaryCols; colIdx++) {
            printf("Element [%d][%d]: ", rowIdx + 1, colIdx + 1);
            scanf("%d", &primaryMatrix[rowIdx][colIdx]);
        }
    }

    printf("\nMatrix entered:\n");
    for (rowIdx = 0; rowIdx < primaryRows; rowIdx++) {
        for (colIdx = 0; colIdx < primaryCols; colIdx++) {
            printf("%5d", primaryMatrix[rowIdx][colIdx]);
        }
        printf("\n");
    }

    printf("\n===== MATRIX TYPES THAT APPLY =====\n");

    isSquare = (primaryRows == primaryCols);
    if (isSquare) printf("- Square Matrix\n");
    else          printf("- Rectangular Matrix\n");

    if (primaryRows == 1) printf("- Row Matrix\n");
    if (primaryCols == 1) printf("- Column Matrix\n");

    isZero = 1;
    for (rowIdx = 0; rowIdx < primaryRows; rowIdx++) {
        for (colIdx = 0; colIdx < primaryCols; colIdx++) {
            if (primaryMatrix[rowIdx][colIdx] != 0) isZero = 0;
        }
    }
    if (isZero) printf("- Zero / Null Matrix\n");

    if (isSquare) {
        isDiagonal = 1; isUpperTriangular = 1; isLowerTriangular = 1; 
        isSymmetric = 1; isSkewSymmetric = 1; isScalar = 1; isIdentity = 1;
        
        int firstDiagElement = primaryMatrix[0][0];

        for (rowIdx = 0; rowIdx < primaryRows; rowIdx++) {
            for (colIdx = 0; colIdx < primaryCols; colIdx++) {
                
                if (rowIdx != colIdx) {
                    if (primaryMatrix[rowIdx][colIdx] != 0) {
                        isDiagonal = 0;
                        isScalar = 0;
                        isIdentity = 0;
                    }
                    if (rowIdx > colIdx && primaryMatrix[rowIdx][colIdx] != 0)  isUpperTriangular = 0;
                    if (rowIdx < colIdx && primaryMatrix[rowIdx][colIdx] != 0)  isLowerTriangular = 0;
                } else {
                    if (primaryMatrix[rowIdx][colIdx] != firstDiagElement) isScalar = 0;
                    if (primaryMatrix[rowIdx][colIdx] != 1) isIdentity = 0;
                    if (primaryMatrix[rowIdx][colIdx] != 0) isSkewSymmetric = 0; // Skew-symmetric must have 0s on diagonal
                }
                if (primaryMatrix[rowIdx][colIdx] != primaryMatrix[colIdx][rowIdx]) isSymmetric = 0;
                if (primaryMatrix[rowIdx][colIdx] != -primaryMatrix[colIdx][rowIdx]) isSkewSymmetric = 0;
            }
        }

        if (isDiagonal && !isZero) printf("- Diagonal Matrix\n");
        if (isScalar && !isZero)   printf("- Scalar Matrix\n");
        if (isIdentity)            printf("- Identity Matrix\n");
        if (isUpperTriangular)     printf("- Upper Triangular Matrix\n");
        if (isLowerTriangular)     printf("- Lower Triangular Matrix\n");
        if (isSymmetric)           printf("- Symmetric Matrix\n");
        if (isSkewSymmetric)       printf("- Skew-Symmetric Matrix\n");
    }

    printf("\nDo you want to check equality with a second matrix? (y/n): ");
    scanf(" %c", &userChoice);

    if (userChoice == 'y' || userChoice == 'Y') {
        printf("\nEnter number of rows for second matrix: ");
        scanf("%d", &secondaryRows);
        printf("Enter number of columns for second matrix: ");
        scanf("%d", &secondaryCols);

        if (secondaryRows < 1 || secondaryRows > 5 || secondaryCols < 1 || secondaryCols > 5) {
            printf("Invalid size for second matrix.\n");
        } else {
            for (rowIdx = 0; rowIdx < secondaryRows; rowIdx++) {
                for (colIdx = 0; colIdx < secondaryCols; colIdx++) {
                    printf("Second matrix [%d][%d]: ", rowIdx + 1, colIdx + 1);
                    scanf("%d", &secondaryMatrix[rowIdx][colIdx]);
                }
            }
            
            isEqual = (primaryRows == secondaryRows && primaryCols == secondaryCols);
            for (rowIdx = 0; rowIdx < primaryRows && isEqual; rowIdx++) {
                for (colIdx = 0; colIdx < primaryCols; colIdx++) {
                    if (primaryMatrix[rowIdx][colIdx] != secondaryMatrix[rowIdx][colIdx]) isEqual = 0;
                }
            }
            
            printf("\n===== EQUALITY RESULT =====\n");
            if (isEqual) printf("The matrices are EQUAL.\n");
            else         printf("The matrices are NOT equal.\n");
        }
    }
    return 0;
}
