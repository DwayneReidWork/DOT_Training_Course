#include <stdio.h>

int main()
{
    char input[50];
    printf("Input a line of text: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        printf("You entered: %s\n", input);
    }
}