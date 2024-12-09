#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Car struct
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
};

int main() {
    float total = 0;  // Initialize total as 0
    float average_price;  // Use float to store the average price
    // Dynamically allocate memory (this allocation isn't used in this code, but here for demonstration)
    struct Car *carPtr = (struct Car*) malloc(sizeof(struct Car));

    if (carPtr == NULL) {
        // Check if malloc failed
        printf("Memory allocation failed\n");
        return 1;  // Exit if memory allocation failed
    }

    struct Car cars[2];  // Declare an array of cars

    // Input details for each car
    for (int i = 0; i < 2; i++) {
        printf("Please enter your car's make: ");
        scanf(" %[^\n]%*c", cars[i].make); // Notice the space before %[^\n]

        printf("Please enter your car's model: ");
        scanf(" %[^\n]%*c", cars[i].model); // Space before %[^\n] to skip leading whitespace

        printf("Please enter your car's year: ");
        scanf("%d", &cars[i].year); // Use & to pass the address

        printf("Please enter your car's price: ");
        scanf("%f", &cars[i].price); // Use & to pass the address
    }

    // Calculate the total price of the cars
    for (int i = 0; i < 2; i++) {
        total += cars[i].price;
    }
    
    // Calculate the average price
    average_price = total / 2;

    // Display the details of the cars
    printf("\nCar Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n\n", cars[i].price); // Print price with 2 decimal places
    }

    // Print the average price
    printf("The average price of all cars is $%.2f\n", average_price);

    // Free the dynamically allocated memory
    free(carPtr);

    return 0;
}