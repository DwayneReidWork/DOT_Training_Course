#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"
#include "utility_functions.h"

int main()
{
    int array_size = 1000;
    int *original_array = generateRandomArray(array_size);
    int *random_array;

    printf("Current size of the generated arrays: %d\n", array_size);
    printf("A microsecond is a millionth of a second, or a thousandth of one millisecond!\n");

    // Run each sort and measure its execution time
    random_array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
    {
        random_array[i] = original_array[i];
    }
    printWrapper("Bubble", measureExecutionTime(random_array, array_size, bubbleSort));
    free(random_array);

    random_array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
    {
        random_array[i] = original_array[i];
    }
    printWrapper("Selection", measureExecutionTime(random_array, array_size, selectionSort));
    free(random_array);

    random_array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
    {
        random_array[i] = original_array[i];
    }
    printWrapper("Insertion", measureExecutionTime(random_array, array_size, insertionSort));
    free(random_array);

    random_array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
    {
        random_array[i] = original_array[i];
    }
    printWrapper("Merge", measureExecutionTime(random_array, array_size, mergeSortWrapper));
    free(random_array);

    random_array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
    {
        random_array[i] = original_array[i];
    }
    printWrapper("Quick", measureExecutionTime(random_array, array_size, quickSortWrapper));
    free(random_array);

    free(original_array);
    return 0;
}