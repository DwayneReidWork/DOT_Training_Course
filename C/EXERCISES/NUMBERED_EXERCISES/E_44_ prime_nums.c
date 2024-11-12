#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // Not prime if less than or equal to 1
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

int main() {
    int num;

    // User input
    printf("Please enter a number: ");
    scanf("%d", &num);

    // Checking if the number is prime
    if (is_prime(num)) {
        printf("Number %d is prime.\n", num);
    } else {
        printf("Number %d is not prime.\n", num);
    }

    return 0;
}