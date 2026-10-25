#include<stdio.h>
int square(int x){
    return x * x;
}
int negate(int x){
    return -x;
}
int isEven(int x){
    return (x % 2 == 0) ? 1 : 0;
}
int isPositive(int x){
    return (x > 0) ? 1 : 0;
}
void applyToArray(int *arr, int n, int (*fn)(int)){
    for (int i = 0; i < n; i++){
        *(arr + i) = fn(*(arr + i));
    }
}
int countIf(int *arr, int n, int (*pred)(int)){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (pred(*(arr + i))){
            count++;
        }
    }
    return count;
}
void printGeneric(void *data, char type, int n){
    if (type == 'i') {
        int *ptr = (int *)data;
        for (int i = 0; i < n; i++){
            printf("%d ", *(ptr + i));
        }
        printf("\n");
    } else if (type == 'f') {
        float *ptr = (float *)data;
        for (int i = 0; i < n; i++){
            printf("%.2f ", *(ptr + i));
        }
        printf("\n");
    } else if (type == 'c') {
        char *ptr = (char *)data;
        for (int i = 0; i < n; i++){
            printf("%c ", *(ptr + i));
        }
        printf("\n");
    } else {
        printf("Invalid type '%c' for printGeneric\n", type);
    }
}
int main(){
    int arr[50] = {3, -2, 8, -5, 6};
    int n;

    while (1){
        printf("Enter n (1-50): ");
        scanf("%d", &n);
        if (n >= 1 && n <= 50) {
            break;
        }
        printf("Invalid size\n");
    }

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);
    printf("After negate: ");
    printGeneric(arr, 'i', n);

    int posCount = countIf(arr, n, isPositive);
    printf("Positive values after negate: %d\n", posCount);

    int evenCount = countIf(arr, n, isEven);
    printf("Even values after negate: %d\n", evenCount);

    float fArr[] = {1.50f, 2.25f};
    printf("Float print (type f): ");
    printGeneric(fArr, 'f', 2);

    printGeneric(arr, 'x', n);
    return 0;
}
