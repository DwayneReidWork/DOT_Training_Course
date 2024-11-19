#include <stdio.h>
#include <stdlib.h>  // For strtol
#include <errno.h>   // For errno
#include <string.h>  // For strerror

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Check if the user has passed exactly one argument
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;  // Return an error code
    }

    // Convert the string argument to a long integer using strtol
    int num1 = atoi(argv[1]);

    // Check if the entire string was a valid number
    if (num1 < 0 ) {
        // If endptr points to a non-null character, the string is invalid
        fprintf(stderr, "Invalid input: %s\n", argv[1]);
        return 1;
    }

    // Check if the number is 0 and the input wasn't "0" (since strtol returns 0 on failure)
    //leftover since i switched from strtol to atoi()
    if (num1 == 0 && argv[1][0] != '0') {
        perror("Invalid input");
        return 1;
    }

    // Perform the calculation and display the result
    printf("Number: %ld\nNumber Squared: %ld\n", num1, num1 * num1);
    return 0;
}