#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "sorting_algorithms.h"
#include "utility_functions.h"


void printWrapper(const char* type_of_sort, long double duration)
{
    printf("Duration of %10s: %010.3Lf microseconds, or %010.5Lf milliseconds!\n", type_of_sort, duration, duration / 1000);
}

void mergeSortWrapper(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}

void quickSortWrapper(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
}

int* generateRandomArray(const int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    srand(12345);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    return arr;
}

double measureExecutionTime(int *arr, int size, void (*operation)(int *, int))
{
    struct timespec start, end;

    // Start the timer
    if (clock_gettime(CLOCK_MONOTONIC, &start) == -1)
    {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    // Execute the operation
    operation(arr, size);

    // End the timer
    if (clock_gettime(CLOCK_MONOTONIC, &end) == -1)
    {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    // Calculate elapsed time in microseconds
    double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + 
                     (end.tv_nsec - start.tv_nsec) / 1e3;

    return elapsed; // Return time in microseconds
}