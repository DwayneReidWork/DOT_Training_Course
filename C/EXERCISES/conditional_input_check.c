#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter some text: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Use strcspn to find the length up to the first newline
        size_t length = strcspn(input, "\n");
        // Remove the newline char
        input[length] = '\0';
        // Check if the input starts with '#'
        if (input[0] == '#')
        {
            printf("Python Comment Detected!!!\n");
        }
        //checks if it starts with double slashes
        else if(input[0] == '/' && input[1] == '/')
        {
            printf("C Comment Detected!!!\n");
        }
        //checks if its a blank line
        else if(input[0] == NULL)
        {
            printf("You must enter something!!!\n");
        }
        else
        {
            printf("You entered: '%s' and it is %d characters long.\n", input, length);
        }
    }
    return 0;
}
