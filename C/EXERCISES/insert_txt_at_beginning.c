#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[500];  // A large enough buffer to hold the file content
    char sentence_added_to_front[] = "This sentence is added to the front.\n";

    // Open the file for reading
    FILE *filePtr = fopen("C:\\Users\\Dreid\\Desktop\\DOT_Training_Course\\C\\EXERCISES\\example.txt", "r");

    if (filePtr == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read the entire content of the file into the buffer
    char fileContent[500];
    size_t index = 0;

    while (fgets(buffer, sizeof(buffer), filePtr) != NULL)
    {
        // Copy the content into fileContent buffer
        strcpy(fileContent + index, buffer);
        index += strlen(buffer);
    }
    fclose(filePtr);  // Close the file after reading

    // Reopen the file for writing (this will overwrite the file)
    filePtr = fopen("C:\\Users\\Dreid\\Desktop\\DOT_Training_Course\\C\\EXERCISES\\beginning.txt", "w");

    if (filePtr == NULL)
    {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    // Write the sentence to the top of the file
    fprintf(filePtr, "%s", sentence_added_to_front);

    // Write the original file content
    fprintf(filePtr, "%s", fileContent);

    // Close the file after writing
    fclose(filePtr);

    printf("Sentence added at the top of the file successfully.\n");

    return 0;
}