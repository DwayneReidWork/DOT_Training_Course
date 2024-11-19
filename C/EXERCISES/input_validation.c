#include <stdio.h>
#include <errno.h>
#include <string.h> // For strerror

int main() {
    int num;
    errno = 0; // Reset errno before usage

    printf("Enter a number: ");
    
    if (scanf("%d", &num) != 1) {
        errno = EINVAL; // Set errno to an appropriate error code
        //prints a custom error message ("Invalid input") followed by a colon and a description of the error string associated with the current value of errno
        perror("Invalid input");
        //2 ways to print the same basic info?
        printf("Error description: %s\n", strerror(errno));
    } else {
        printf("The square of %d is %d\n", num, num*num);
    }
    return 0;
}