#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Pointer to the first element of the array
    int i;

    // Access array elements using pointer arithmetic
    printf("Array elements using pointers:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i + 1, *(ptr + i)); // increment counter and pointer [also dereference counter with the asterisk to get the value there{proof of concept run it without the asterist}]
    }

    return 0;
}