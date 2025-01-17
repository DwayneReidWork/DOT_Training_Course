#include <stdio.h>

int main()
{
    char buffer[100];
    FILE *filePtr = fopen("example.txt", "r");
    if (filePtr == NULL)
    {
        //error handling for if file doesnt open/exist
        printf("Failed to open file.\n");
        return 1;
    }
    while (filePtr != NULL)
    {
        while(fgets(buffer, sizeof(buffer), filePtr) != NULL)
        {
            printf("%s",buffer);
        }
    // perform file operations here//
    fclose(filePtr);
    return 0;
}