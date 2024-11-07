#include <stdio.h>

int main() {
    char str[] = "Hello";
    //creates a pointer to the string
    char *ptr = str ;

    //while the pointer isn't pointing to the null charachter
    while (*ptr != '\0') {
        //print the char
        printf("%c\n", *ptr); //get the char by dereferencing the pointer (see asterisk)
        ptr++; //increment the pointer through the string
    }
    return 0;
}