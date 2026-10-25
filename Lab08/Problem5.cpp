#include<stdio.h>
void printGrid(int (*grid)[5]){
    for (int r = 0; r < 5; r++){
        for (int c = 0; c < 5; c++){
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}
int countNeighbours(int (*grid)[5], int row, int col){
    int count = 0;
    for (int dr = -1; dr <= 1; dr++){
        for (int dc = -1; dc <= 1; dc++){
            if (dr == 0 && dc == 0) continue;
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5){
                count += (grid[nr][nc] & 1);
            }
        }
    }
    return count;
}
void nextGeneration(int (*grid)[5]){
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++){
            int live = countNeighbours(grid, r, c);
            int current = grid[r][c] & 1;

            if (current == 1) {
                if (live == 2 || live == 3){
                    grid[r][c] |= 2;
                }
            } else {
                if (live == 3){
                    grid[r][c] |= 2;
                }
            }
        }
    }
    for (int r = 0; r < 5; r++){
        for (int c = 0; c < 5; c++){
            grid[r][c] >>= 1;
        }
    }
}
int main() {
    int grid[5][5] = {0};
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;
    int gens;
    while (1) {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
        if (gens >= 0 && gens <= 50){
            break;
        }
        printf("Invalid number\n");
    }

    for (int g = 0; g <= gens; g++){
        printf("Generation %d:\n", g);
        printGrid(grid);
        if (g < gens){
            nextGeneration(grid);
        }
    }
    return 0;
}
