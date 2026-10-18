#include<stdio.h>
int main()
{
    int dataCube[3][3][3];
    int currentLayerIdx, comparisonLayerIdx, rowIdx, colIdx;
    int matchingElementsCount;

    printf("Enter 27 elements:\n");
    for (currentLayerIdx = 0; currentLayerIdx < 3; currentLayerIdx++) {
        for (rowIdx = 0; rowIdx < 3; rowIdx++) {
            for (colIdx = 0; colIdx < 3; colIdx++) {
                scanf("%d", &dataCube[currentLayerIdx][rowIdx][colIdx]);
            }
        }
    }
    for (currentLayerIdx = 0; currentLayerIdx < 3; currentLayerIdx++) {
        printf("\nLayer %d:\n", currentLayerIdx + 1);
        for (rowIdx = 0; rowIdx < 3; rowIdx++) {
            for (colIdx = 0; colIdx < 3; colIdx++) {
                printf("%5d", dataCube[currentLayerIdx][rowIdx][colIdx]);
            }
            printf("\n");
        }
    }
    printf("\n");
    for (currentLayerIdx = 0; currentLayerIdx < 3; currentLayerIdx++) {
        for (comparisonLayerIdx = currentLayerIdx + 1; comparisonLayerIdx < 3; comparisonLayerIdx++) {
            matchingElementsCount = 0;
            for (rowIdx = 0; rowIdx < 3; rowIdx++) {
                for (colIdx = 0; colIdx < 3; colIdx++) {
                    if (dataCube[currentLayerIdx][rowIdx][colIdx] == dataCube[comparisonLayerIdx][rowIdx][colIdx]) {
                        matchingElementsCount++;
                    }
                }
            }
            printf("Layer %d vs Layer %d: %d/9 match (%.1f%%) - %s\n", 
                   currentLayerIdx + 1, 
                   comparisonLayerIdx + 1,
                   matchingElementsCount, 
                   matchingElementsCount * 100.0 / 9, 
                   matchingElementsCount == 9 ? "IDENTICAL" : "DISTINCT");
        }
    }
    return 0;
}
