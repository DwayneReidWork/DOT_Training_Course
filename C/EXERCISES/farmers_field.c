#include <stdio.h>

// Function to calculate the area of the field
int AreaOfField(int *a, int *b) {
    int area;
    area = (*a) * (*b);  // Multiply the dereferenced values of length and width
    return area;
}

// Function to convert square feet to acres
float ConvertToAcres(int area) {
    int conversion_factor = 43560;  // 1 acre = 43,560 square feet
    return (float)area / conversion_factor;
}

int main() {
    // Declare variables
    int length, width, area;
    float acres;

    // Get the user input
    printf("Please enter the length and width of your farm (in feet): ");
    scanf("%d %d", &length, &width); // Assign the values to the variables

    // Calculate the area in square feet
    area = AreaOfField(&length, &width);

    // Convert the area to acres
    acres = ConvertToAcres(area);

    // Output the calculated area in both square feet and acres
    printf("The area of the field is: %d square feet\n", area);
    printf("The area of the field in acres is: %.4f acres\n", acres);

    return 0;
}