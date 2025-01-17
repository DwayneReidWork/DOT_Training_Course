/* implement a program to sort an array  of integers in ascending or descending order based on a function pointer passed to the sorting function*/

#include <stdio.h>
#include <stdlib.h>

// Function for ascending order comparison
int ascending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function for descending order comparison
int descending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to sort an array using qsort
void sortArray(int arr[], int size, int (*compare)(const void *, const void *)) {
    qsort(arr, size, sizeof(int), compare);
}

int main() {
    int arr[5] = {5, 3, 8, 1, 2};

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in ascending order
    printf("Sorted in ascending order:\n");
    sortArray(arr, 5, ascending);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    printf("Sorted in descending order:\n");
    sortArray(arr, 5, descending);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
