#include <stdio.h>

int main() {
    char str[] = "hello";
    char *ptr = str;

    while (*ptr != '\0') {
        if (*ptr >= 97 && *ptr <= 122) {
            char new_letter = *ptr - 32;  // Convert to uppercase
            printf("%c\n", new_letter);
        } else {
            printf("%c\n", *ptr);  // Print character as is if not lowercase
        }
        ptr++;  // Move to the next character
    }
    return 0;
}