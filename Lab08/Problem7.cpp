#include<stdio.h>
void reverseArray(int *arr, int n){
    int *start = arr;
    int *end = arr + n - 1;

    while (start < end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
void printArray(const int *arr, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
int main(){
    int n;
    int playlist[20];

    while (1){
        printf("Enter number of songs: ");
        scanf("%d", &n);
        if (n >= 1 && n <= 20){
            break;
        }
        printf("Invalid size\n");
    }
    printf("Enter song IDs:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", playlist + i);
    }
    printf("Original: ");
    printArray(playlist, n);

    reverseArray(playlist, n);

    printf("Reversed: ");
    printArray(playlist, n);
    return 0;
}
