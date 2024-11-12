#include <stdio.h>
#include <string.h>

int main() {
    char string1[] = "Hello, World!";
    char copied_string[5];

    //strcpy(dest, src)
    strcpy(copied_string, string1);

    printf("%s", copied_string);
    return 0;
}
