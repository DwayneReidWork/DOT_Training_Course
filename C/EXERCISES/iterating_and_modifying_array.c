/* declare an arrray of 10 integers amd dynamically generate these integers. Then use pointer to iterate through array and multiply each element by its index*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
    // Initialize array
    int arr[10];
    int *ptr = arr; // Pointer to the start of the array
    int counter = 0;

    // Fill the array using the pointer
    for (int i = 0; i < 10; i++)
    {
        *(ptr + i) = counter; // Use pointer arithmetic to set values
        printf("Array[%d]: %d\n", i + 1, *(ptr + i) * 10);
        counter++;
    }

    return 0;
}