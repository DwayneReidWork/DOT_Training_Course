#include <stdio.h>

int main() {
    char *ptr = "Hello World!";
    int counter = 0;

    while (*ptr != '\0') {
        counter++;
        ptr++;
    }
    printf("Your string is %d charachters long\n", counter);
    return 0;
}