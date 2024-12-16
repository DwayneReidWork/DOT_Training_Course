#include <stdio.h>

int main()
{
    FILE *filePtr = fopen("example.txt", "r");
    if (filePtr ==NULL)
    {
        //error handling for if file doesnt open/exist
        printf("Failed to open file.\n");
        return 1;
    }
    // perform file operations here//
    fclose(filePtr);
    return 0;
}