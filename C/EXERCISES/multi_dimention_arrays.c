/*Declare 2d array (3x3 matrix) and write a function that takes a pointer to this matrix and prints its elements in a spiral order*/


#include <stdio.h>

void spiralPrint(int arr[3][3], int rows, int cols) {
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[top][i]);
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;

        // Print bottom row if applicable
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }

        // Print left column if applicable
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Spiral Order: ");
    spiralPrint(arr, 3, 3);

    return 0;
}