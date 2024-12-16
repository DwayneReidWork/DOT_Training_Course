#include <stdio.h>
#include <string.h>

// int main() {
//     char string1[] = "Hello, World!";
//     char copied_string[5];

//     //strcpy(dest, src)
//     strncpy(copied_string, string1, 5);
//     copied_string[5] = '\0';

//     printf("%s", copied_string);
//     return 0;
// }

//dynamic
int main() {
    char src[] = "This string is too long for the buffer";
    char dest[15];
    strncpy(dest, src, sizeof(dest)-1);
    dest[sizeof(dest) -1] = '\0';

    printf("Safetly copied string: %s\n", dest);
    return 0;
}