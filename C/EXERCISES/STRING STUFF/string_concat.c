#include <stdio.h>
#include <string.h>

int main() {
    char string1[40] = "This is string 1.";
    char string2[] = "This is string 2.";

    if ((strlen(string1) + strlen(string2) < sizeof(string1))) {
        strncat(string1, string2, ((sizeof(string1)-strlen(string1)-1)));
        printf("%s\n", string1);
    }
    else {
        printf("Buffer Overflow!");
    }
    
    return 0;
}
