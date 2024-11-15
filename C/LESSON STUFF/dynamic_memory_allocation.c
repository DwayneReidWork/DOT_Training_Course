#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* numbers;
    int size;

    printf("Enter the size of an array: ");
    scanf("%d", &size);

    //dynamically allocate memory for the array
    numbers = (int*)malloc(size*sizeof(int));

    //check if creation was successful
    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    //store values in the dynamically allocated array
    for (int i = 0; i < size; i++)
    {
        numbers[i] = i+1;
    }
    //print the values
    for (int i = 0; i < size; i++)
    {
        printf("Numbers[%d] = %d\n", i, numbers[i]);
    }
    //free the dynamically allocated memory.
    free(numbers);

    return 0;
}