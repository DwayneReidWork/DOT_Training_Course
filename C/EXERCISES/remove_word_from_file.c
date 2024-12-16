#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *filePtr = fopen("example.txt", "r");
    FILE *tempPtr = fopen("temp.txt", "w");
    if (filePtr == NULL || tempPtr == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
    char buffer[256];
    const char* word_to_delete = "remove";

    while (fgets(buffer, sizeof(buffer), filePtr) != NULL)
    {
        if (strstr(buffer, word_to_delete) == NULL)
        {
            fputs(buffer,tempPtr);
        }
    }

    fclose(filePtr);
    fclose(tempPtr);

    remove("example.txt");
    rename("temp.txt", "example.txt");

    printf("Lines containing '%s' have been removed.\n", word_to_delete);
    return 0;
}