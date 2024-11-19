#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer;
    size_t buffsize = 50;
    size_t input_length = 0;

    buffer = (char *)malloc(buffsize * sizeof(char));
    if (buffer == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    printf("Enter a long line of text: ");
    while (fgets(buffer + input_length, buffsize - input_length, stdin) != NULL)
    {
        input_length += strlen(buffer + input_length);

        // Check if input_length is reaching the buffer size and no newline was found
        if (buffer[input_length - 1] != '\n' && input_length == buffsize - 1)
        {
            buffsize *= 2; // Double the buffer size
            char *new_buffer = realloc(buffer, buffsize * sizeof(char));
            if (new_buffer == NULL)
            {
                printf("Failed to resize memory!\n");
                free(buffer);
                return 1;
            }
            buffer = new_buffer;
        }
        else
        {
            break;
        }
    }
    printf("You entered: %s\n", buffer);
    free(buffer);
    return 0;
}