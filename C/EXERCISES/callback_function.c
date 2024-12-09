#include <stdio.h>
#include <stdlib.h>

// Function to perform operation using a callback
int do_operation(int num1, int num2, int (*func_ptr)(int, int)) {
    int result = func_ptr(num1, num2);  // Call the function through the pointer
    printf("Your answer is: %d\n", result);
    return result;  // Return the result
}

// Operation functions
int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    if (num2 != 0)  // Check for division by zero
        return num1 / num2;
    printf("Error: Division by zero!\n");
    return 0;
}

int main() {
    int num1, num2;
    char funct;
    int (*func_ptr)(int, int);  // Declare a function pointer

    // Prompt user input
    printf("Please enter 2 integers followed by the operation (+, -, *, /): ");
    scanf("%d %d %c", &num1, &num2, &funct);

    // Assign the appropriate function to the function pointer
    switch (funct) {
        case '+':
            func_ptr = add;
            break;
        case '-':
            func_ptr = subtract;
            break;
        case '*':
            func_ptr = multiply;
            break;
        case '/':
            func_ptr = divide;
            break;
        default:
            printf("Invalid operation specified.\n");
            return 1;  // Exit with an error code
    }

    // Perform the operation
    do_operation(num1, num2, func_ptr);

    return 0;
}