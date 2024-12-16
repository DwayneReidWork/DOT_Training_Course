#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sorting algorithm prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSortWrapper(int arr[], int n); // Wrapper for mergeSort
void quickSortWrapper(int arr[], int n); // Wrapper for quickSort

// Supplementary sorting functions
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// Utility functions
int* generateRandomArray(const int size);
double measureExecutionTime(int *arr, int size, void (*operation)(int *, int));
void printWrapper(const char* type_of_sort, long double duration);

int main()
{
    int array_size = 1000000;
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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}