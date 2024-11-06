#include <stdio.h>

void swap(int *a, int *b) {
    // Function to swap 2 integers using void swap
    //temp = temporary
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 5;
    int num2 = 10;

    printf("Before swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    // Call swap function with addresses of num1 and num2 
    swap(&num1, &num2);

    printf("After swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
