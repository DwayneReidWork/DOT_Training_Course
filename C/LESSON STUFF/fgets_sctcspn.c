#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[256]; // Define buffer with a suitable size
    
    printf("Input a line of text: ");
    
    // Read input using fgets
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        // Remove the newline character, if present
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Trim trailing spaces and tabs
        size_t len = strlen(buffer);
        while (len > 0 && (buffer[len - 1] == ' ' || buffer[len - 1] == '\t'))
        {
            buffer[--len] = '\0';
        }
        
        // Print the trimmed input
        printf("Trimmed input: \"%s\"\n", buffer);
    }
    else
    {
        printf("Error reading input.\n");
    }
    
    return 0;
}