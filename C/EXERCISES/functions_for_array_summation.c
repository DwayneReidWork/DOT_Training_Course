/*Write a function that takes an array and its size as arguments and returns the sum of all even numbers. Pass the array using a pointer*/


#include <stdlib.h>
#include <stdio.h>

int add_even_array(int* array, int size) {
    int tally = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {  // Check if the array element is even
            tally += array[i];   // Add the even element to the tally
        }
    }
    return tally;  // Return the sum of even elements
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    /*the below line is because youre given size in bytes and dividing it by the data 
    type give you the size of the data type */
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = add_even_array(ptr, size);  // Pass the array and its size
    printf("Sum of even numbers in the array: %d\n", sum);
    return 0;
}