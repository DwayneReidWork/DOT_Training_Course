#include <stdio.h>

int main() {
    char str[] = "Hello";  // Use an array to allow modification

    // To change 'e' to 'a'
    char *ptr = str;  // Pointer to traverse the string
    while (*ptr != '\0') {
        // Correcting the printf statement
        printf("Memory Location of Pointer: %p | Memory location of character '%c': %p\n", &ptr, *ptr, ptr);
        if (*ptr == 'e') {
            *ptr = 'a';  // Modify 'e' to 'a'
        }
        ptr++;
    }

    printf("Our new string: %s\n", str);  // Print the modified string
    return 0;
}