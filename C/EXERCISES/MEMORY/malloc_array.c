#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* numbers;
    int size = 5;

    //dynamically allocate memory for the array
    numbers = (int*)malloc(size*sizeof(int));

    //store values in the dynamically allocated array
    for (int i = 0; i < size; i++)
    {
        numbers[i] = ((i+1)*5);
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