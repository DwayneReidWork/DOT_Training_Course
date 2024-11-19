#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        // Check if the user has passed exactly one argument
        printf("Usage: %s <positive integer>\n", argv[0]);
        return 1;  // Return an error code
    }

    char *endptr;
    //pass in the argv plus pointer plus base value (base 10 is decimals)
    long num = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || num <= 0)
    {
        printf("Invalid input. Please enter a positive integer.");
        return 1;
    }

    printf("The square of '%ld' is '%ld'.", num, num*num);
    return 0;
}