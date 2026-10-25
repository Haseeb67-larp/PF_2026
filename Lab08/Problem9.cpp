#include<stdio.h>
int sumShelf(const int *shelf, int count){
    int sum = 0;
    for (int i = 0; i < count; i++){
        sum += *(shelf + i);
    }
    return sum;
}
int findLargestShelf(const int *counts, int shelves){
    int largestIdx = 0;
    int maxBooks = *counts;

    for (int i = 1; i < shelves; i++){
        if (*(counts + i) > maxBooks){
            maxBooks = *(counts + i);
            largestIdx = i;
        }
    }
    return largestIdx;
}
int main(){
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};
    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int numShelves = 3;

    for (int i = 0; i < numShelves; i++){
        int total = sumShelf(shelves[i], counts[i]);
        printf("Shelf %d ID total:\n%d\n", i + 1, total);
    }
    int largest = findLargestShelf(counts, numShelves);
    printf("Shelf with the most books: Shelf %d (%d books)\n", largest + 1, counts[largest]);
    return 0;
}
