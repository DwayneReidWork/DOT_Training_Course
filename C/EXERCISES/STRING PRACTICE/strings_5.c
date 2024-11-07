#include <stdio.h>

//swap 2 letters in a string


void replaceChar(char *str, char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char greeting[] = "Hello, World!";
    replaceChar(greeting, 'o', 'a');
    printf("Modified string: %s\n", greeting);
    return 0;
}