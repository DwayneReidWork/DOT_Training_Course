#include <stdio.h>

// Define constants for feature flags using bitwise shifts
#define FEATURE_A (1 << 0) // 1 << 0 = 0001 (binary), represents Feature A
#define FEATURE_B (1 << 1) // 1 << 1 = 0010 (binary), represents Feature B
#define FEATURE_C (1 << 2) // 1 << 2 = 0100 (binary), represents Feature C
#define FEATURE_D (1 << 3) // 1 << 3 = 1000 (binary), represents Feature D

void toBinary(int num) {
    for (int i = 3; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

int main() {
    unsigned int flags = 0;      // Stores the current state of all features (all OFF initially)
    unsigned int user_select;    // Stores the user's input for feature selection

    do {
        // Display the current state of the flags
        printf("Current flags: %d\n", flags);
        printf("Current flags in binary: ");
        toBinary(flags);

        // Prompt user for input
        printf("Enter 1-4 for options A, B, C, D (or 0 to exit): ");
        if (scanf("%u", &user_select) != 1) { // Handle non-numeric input
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        // Handle user input using a switch-case structure
        switch (user_select) {
        case 0: // User chooses to exit
            printf("Exit code detected! Closing program.\n");
            break;

        case 1: // Toggle Feature A
            printf("Toggling Feature A.\n");
            flags ^= FEATURE_A; // Toggle the bit for Feature A
            break;

        case 2: // Toggle Feature B
            printf("Toggling Feature B.\n");
            flags ^= FEATURE_B; // Toggle the bit for Feature B
            break;

        case 3: // Toggle Feature C
            printf("Toggling Feature C.\n");
            flags ^= FEATURE_C; // Toggle the bit for Feature C
            break;

        case 4: // Toggle Feature D
            printf("Toggling Feature D.\n");
            flags ^= FEATURE_D; // Toggle the bit for Feature D
            break;

        default: // Handle invalid inputs
            printf("Invalid input, please enter a number between 0 and 4.\n");
            while (getchar() != '\n'); // Clear the input buffer
            break;
        }
    } while (user_select != 0); // Continue looping until the user enters 0

    return 0; // Exit the program
}