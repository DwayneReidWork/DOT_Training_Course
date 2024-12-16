#include <stdio.h>
#include <stdlib.h>


int main() {
    int *numbers;
    int size = 8;
    
    // Allocating memory for 5 integers, each initialized to 0
    numbers = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        numbers[i] = (i*2);
        printf("Numbers[%d] = %d\n", i, numbers[i]);
    }
    //print the values
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Numbers[%d] = %d\n", i, numbers[i]);
    // }

//free the dynamically allocated memory.
free(numbers);
return 0;
}