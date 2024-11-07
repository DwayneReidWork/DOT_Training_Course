#include <stdio.h>

//print a string letter by letter on  new lines

char my_first_program[] = "Hello World!";

void print_func(char* word) { //char is a pointer to the word passed in.
    for (int i = 0; word[i] != '\0'; i++) {
        printf("%c\n", word[i]);
    }
}

int main() {
    print_func(my_first_program);
    return 0;
}

//can also rewrite this using 'sizeof(my_first_program)' since we werent using '#include <string.h>' yet.