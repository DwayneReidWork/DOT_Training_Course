#include <stdio.h>

int *largerNumber(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    int *larger = largerNumber(&num1, &num2);

    printf("The larger number is %d\n", *larger);

    return 0;
}