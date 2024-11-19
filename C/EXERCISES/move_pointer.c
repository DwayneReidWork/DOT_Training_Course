#include <stdio.h>

int main()
{
    char buffer[100];
    // Correct file path with double backslashes
    FILE *filePtr = fopen("C:\\Users\\Dreid\\Desktop\\DOT_Training_Course\\C\\EXERCISES\\example.txt", "r");

    if (filePtr == NULL)
    {
        // Error handling if the file doesn't open or doesn't exist
        printf("Failed to open file.\n");
        return 1;
    }

    // Move the file pointer to 450 bytes from the end
    if (fseek(filePtr, 450, SEEK_SET) != 0)
    {
        printf("Failed to seek to the specified position in the file.\n");
        fclose(filePtr);
        return 1;
    }

    // Read and print the file starting from the 450-byte offset
    printf("This is the file content from 450 bytes offset:\n\n");
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file after operations are complete
    fclose(filePtr);
    return 0;
}