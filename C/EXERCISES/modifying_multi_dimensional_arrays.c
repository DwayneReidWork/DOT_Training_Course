/*Implement a function that takes a 2d array (3x3 Matrix) and a scalar value and multiplies each value pf the matrix by the scalar using pointers.*/

#include <stdio.h>

void scale_array(int* array, int rows, int cols, int scale) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(array + i * cols + j) *= scale; // Use pointer arithmetic to access elements
        }
    }
}

int main() {
    int scale = 3;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Scale the array
    scale_array((int*)arr, 3, 3, scale);

    // Print the scaled array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
