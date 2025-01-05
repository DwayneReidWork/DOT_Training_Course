#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct that holds a name and Naughty/Nice Status
struct Person 
{
    char name[50];
    bool status;  // true for Nice, false for Naughty
};

// Function to load the list from the file into the array and increment the counter for each name. (WIP)
void loadList(FILE *file, struct Person list[], int *count)
{
    char buffer[50];
    char status[7];  // Enough space for "Naughty" or "Nice"
    
    // Loop through the file and load the data
    // Reads 6 chars from status column and loads it into a buffer then compares to get naughty or nice.
    while (fscanf(file, "%6s: %[^\n]", status, buffer) == 2)
    {   // Read both status and name
        // Set the status based on the string value
        if (strcmp(status, "Nice") == 0)
        {
            list[*count].status = true;  // Nice
        }
        else if (strcmp(status, "Naughty") == 0)
        {
            list[*count].status = false;  // Naughty
        }
        else
        {
            continue; // Skip if status is neither "Nice" nor "Naughty"
        }
        
        // Copy the name to the list
        strncpy(list[*count].name, buffer, sizeof(list[*count].name) - 1);
        list[*count].name[sizeof(list[*count].name) - 1] = '\0'; // Adds null terminator
        (*count)++;
    }
}

// Function to display both lists
void displayEntireList(struct Person list[], int count)
{
    printf("\nSANTA'S LIST:\n");
    if (count == 0)
    {
        printf("Your list is empty! Get started!!!\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s (%s)\n", i + 1, list[i].name, list[i].status ? "Nice" : "Naughty");
    }
}

// Function to display the Nice list
void displayNiceList(struct Person list[], int count)
{
    printf("\nSANTA'S NICE LIST:\n");
    int foundNice = 0;
    for (int i = 0; i < count; i++)
    {
        //Checks if bool status is true which means nice.
        if (list[i].status)
        {  // Nice
            printf("%d. %s\n", i + 1, list[i].name);
            foundNice = 1;
        }
    }
    if (!foundNice)
    {
        printf("No one is on the Nice list.\n");
    }
}

// Function to display the Naughty list
void displayNaughtyList(struct Person list[], int count)
{
    printf("\nSANTA'S NAUGHTY LIST:\n");
    int foundNaughty = 0;
    for (int i = 0; i < count; i++)
    {
        //Checks if bool status is false for naughty.
        if (!list[i].status)
        {  // Naughty
            printf("%d. %s\n", i + 1, list[i].name);
            foundNaughty = 1;
        }
    }
    if (!foundNaughty)
    {
        printf("No one is on the Naughty list.\n");
    }
}

// Function to remove a name from the list
void removeName(struct Person list[], int *count, int index)
{
    if (*count == 0)
    {
        printf("The list is empty, nothing to remove!\n");
        return;
    }
    
    // Shift elements left to remove the name at 'index'
    for (int i = index; i < *count - 1; i++)
    {
        list[i] = list[i + 1];
    }
    (*count)--;  // Decrease the count
    printf("Person removed successfully.\n");
}

// Function to save the list to a file
void saveListToFile(FILE *file, struct Person list[], int count)
{
    fopen("Santas_List.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s: %s\n", list[i].status ? "Nice" : "Naughty", list[i].name);
    }
    fclose(file);
}