#include<stdio.h>
int add(int a, int b, int *result){
    *result = a + b;
    return 1;
}
int subtract(int a, int b, int *result){
    *result = a - b;
    return 1;
}
int multiply(int a, int b, int *result){
    *result = a * b;
    return 1;
}
int divide(int a, int b, int *result){
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}
int main(){
    int (*ops[])(int, int, int *) = {add, subtract, multiply, divide};
    const char *names[] = {"Add", "Subtract", "Multiply", "Divide"};

    int choice;
    while (1){
        printf("Choice (1-5): ");
        if (scanf("%d", &choice) != 1){
            break;
        }

        if (choice == 5){
            printf("Goodbye.\n");
            break;
        }

        if (choice < 1 || choice > 5){
            printf("Invalid choice\n");
            continue;
        }

        int a, b, res;
        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);

        int opIndex = choice - 1;
        if (ops[opIndex](a, b, &res)){
            printf("%s result: %d\n", names[opIndex], res);
        } else {
            printf("Error: division by zero\n");
        }
    }
    return 0;
}
