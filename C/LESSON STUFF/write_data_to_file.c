#include <stdio.h>

int main()
{
    char buffer[100];
    FILE *filePtr = fopen("output.txt", "w");
    if (filePtr != NULL)
    {
        fprintf(filePtr, "Hello, World!\n");
        fclose(filePtr);
    }
    else
    {
        printf("Failed to open file for writing.");
    }
    return 0;
}