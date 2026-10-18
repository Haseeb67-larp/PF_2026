#include<stdio.h>
int main()
{
    int dataCube[3][3][3];
    int layerIdx, rowIdx, colIdx;
    int layerTotals[3] = {0};
    int grandTotal = 0;
    int maximumValue, minimumValue;

    printf("Enter 27 elements:\n");
    for (layerIdx = 0; layerIdx < 3; layerIdx++) {
        for (rowIdx = 0; rowIdx < 3; rowIdx++) {
            for (colIdx = 0; colIdx < 3; colIdx++) {
                scanf("%d", &dataCube[layerIdx][rowIdx][colIdx]);
            }
        }
    }

    maximumValue = minimumValue = dataCube[0][0][0];
    
    for (layerIdx = 0; layerIdx < 3; layerIdx++) {
        printf("\nLayer %d:\n", layerIdx + 1);
        for (rowIdx = 0; rowIdx < 3; rowIdx++) {
            for (colIdx = 0; colIdx < 3; colIdx++) {
                printf("%5d", dataCube[layerIdx][rowIdx][colIdx]);
                layerTotals[layerIdx] += dataCube[layerIdx][rowIdx][colIdx];
                
                if (dataCube[layerIdx][rowIdx][colIdx] > maximumValue) {
                    maximumValue = dataCube[layerIdx][rowIdx][colIdx];
                }
                if (dataCube[layerIdx][rowIdx][colIdx] < minimumValue) {
                    minimumValue = dataCube[layerIdx][rowIdx][colIdx];
                }
            }
            printf("\n");
        }
        grandTotal += layerTotals[layerIdx];
        printf("Total = %d, Average = %.2f\n", layerTotals[layerIdx], layerTotals[layerIdx] / 9.0);
    }

    printf("\nGrand total = %d\nOverall average = %.2f\n", grandTotal, grandTotal / 27.0);
    printf("Maximum = %d, Minimum = %d\n", maximumValue, minimumValue);
    
    int highestLayerNumber;
    if (layerTotals[0] >= layerTotals[1] && layerTotals[0] >= layerTotals[2]) {
        highestLayerNumber = 1;
    } else if (layerTotals[1] >= layerTotals[2]) {
        highestLayerNumber = 2;
    } else {
        highestLayerNumber = 3;
    }
    printf("Highest layer: %d\n", highestLayerNumber);
    return 0;
}
