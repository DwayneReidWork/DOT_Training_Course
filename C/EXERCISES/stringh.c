#include <stdio.h>
#include <string.h>  // For strlen()

int main() {
    char my_first_program[] = "Hello World";  // String with length 13 (including null terminator)
    
    for (int i = 0; i < strlen(my_first_program); i++) {  // Use strlen() to get the length of the string
        printf("%c", my_first_program[i]);  // Print each character
    }
    printf("\n");  // Print a newline at the end
    return 0;
}
