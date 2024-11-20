#include <stdio.h>
#include <time.h>

int main()
{
    FILE *filePtr = fopen("time.txt", "a");
    time_t now = time(0);
    char timestamp[100];
    struct tm *localTime = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);
    
    if (filePtr != NULL)
    {
        fprintf(filePtr, "%s\n", timestamp);
        fclose(filePtr); // Close the file
        printf("Text successfully written to 'time.txt'.\n");
    }
    else
    {
        printf("Failed to open file for writing.\n");
    }
    return 0;
}