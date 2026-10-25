#include<stdio.h>
int isValidMark(int m){
    return (m >= 0 && m <= 100) ? 1 : 0;
}
void findMinMax(int arr[], int size, int *min, int *max){
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < *min){
            *min = arr[i];
        }
        if (arr[i] > *max){
            *max = arr[i];
        }
    }
}
int main() {
    int marks[5];

    for (int i = 0; i < 5; i++){
        int m;
        while (1){
            printf("Enter mark %d:\n", i + 1);
            scanf("%d", &m);
            if (isValidMark(m)){
                marks[i] = m;
                break;
            } else {
                printf("Invalid mark,\nenter again\n");
            }
        }
    }

    int minVal, maxVal;
    findMinMax(marks, 5, &minVal, &maxVal);

    printf("Lowest mark: %d\n", minVal);
    printf("Highest mark: %d\n", maxVal);
    return 0;
}
