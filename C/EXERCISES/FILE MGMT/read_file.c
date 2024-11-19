#include <stdio.h>

int main()
{
    char buffer[100];
    // Correct file path with double backslashes
    FILE *filePtr = fopen("C:\\Users\\Dreid\\Desktop\\DOT_Training_Course\\C\\EXERCISES\\data.txt", "r");

    if (filePtr == NULL)
    {
        // Error handling if the file doesn't open or doesn't exist
        printf("Failed to open file.\n");
        return 1;
    }

    // Read and print the file line by line
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL)
    {
        printf("%s", buffer);
    }
    // Close the file after operations are complete
    fclose(filePtr);
    return 0;
}
