#include <stdio.h>

int main() {
    char str[] = "This is the string I want to search through for characters";
    char search_letter = 's';
    char *ptr = str;
    int letter_counter = 0;

    while (*ptr != '\0') {
        // Check for both uppercase and lowercase match
        if (*ptr == search_letter || *ptr + 32 == search_letter || *ptr - 32 == search_letter) {
            letter_counter++;
        }
        ptr++;  // Move to the next character in all cases
    }

    printf("The letter '%c' appears %d times.\n", search_letter, letter_counter);

    return 0;
}