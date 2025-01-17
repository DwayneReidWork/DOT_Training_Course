#include <stdio.h>
#include <string.h>

int main()
{
    char input[50];
    printf("Input a line of text: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = '\0';
        printf("You entered: %s and it is %d charachters long.\n", input, strlen(input));
    }
    return 0;
}