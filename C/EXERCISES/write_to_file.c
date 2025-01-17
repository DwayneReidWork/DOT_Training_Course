#include <stdio.h>

int main()
{
    char buffer[100]; // Buffer for user input

    printf("Enter text to write to a file: ");
    fgets(buffer, sizeof(buffer), stdin);

    FILE *filePtr = fopen("output.txt", "w");
    if (filePtr != NULL)
    {
        // Write the user input to the file
        fprintf(filePtr, "%s\n", buffer);
        fclose(filePtr); // Close the file
        printf("Text successfully written to 'output.txt'.\n");
    }
    else
    {
        printf("Failed to open file for writing.\n");
    }
    return 0;
}