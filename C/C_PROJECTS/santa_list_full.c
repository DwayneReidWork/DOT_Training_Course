#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "naughty_or_nice.h"

// Max size for lists
#define MAX_LIST_SIZE 100

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

int main()
{
    struct Person santasList[MAX_LIST_SIZE];
    int listCount = 0;

    // Open the file and load the list (open in "r" mode to read from the file)
    FILE *file = fopen("Santas_List.txt", "r");
    if (file == NULL) 
    {
        printf("No existing data found in Santas_List.txt. Starting fresh.\n");
    }
    else
    {
        loadList(file, santasList, &listCount);
        fclose(file);  // Close the file after loading data
    }

    int uInput;
    while (1) 
    {
        // Menu for the user to select actions
        printf("\nWhat would you like to do?\n");
        printf("1. Add to the list.\n");
        printf("2. Remove from the list\n");
        printf("3. View the entire list\n");
        printf("4. View the Naughty list\n");
        printf("5. View the Nice list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &uInput);
        getchar();  // Consume the newline character

        char inputName[50];
        int statusChoice;

        switch (uInput)
        {
            case 1:  // Add to the list (Naughty/Nice)
                if (listCount >= MAX_LIST_SIZE)
                {
                    printf("List is full, can't add more people.\n");
                    break;
                }

                printf("Enter the name of the person: ");
                fgets(inputName, sizeof(inputName), stdin);
                inputName[strcspn(inputName, "\n")] = '\0';  // Remove newline

                printf("Please select their status:\n1 for Naughty\n2 for Nice\n");
                scanf("%d", &statusChoice);  // Use scanf to read numeric input for status
                getchar();  // Consume the newline character left by scanf

                // Add to the list based on the chosen status
                strncpy(santasList[listCount].name, inputName, sizeof(santasList[listCount].name) - 1);
                santasList[listCount].name[sizeof(santasList[listCount].name) - 1] = '\0';  // Ensure null-termination
                if (statusChoice == 2)
                {
                    santasList[listCount].status = true;  // Nice
                } else if (statusChoice == 1)
                {
                    santasList[listCount].status = false;  // Naughty
                }
                else
                {
                    printf("Invalid choice. Please enter 1 for Naughty or 2 for Nice.\n");
                    break;  // Exit the case and go back to the menu
                }

                listCount++;
                printf("Person added: %s (%s)\n", inputName, santasList[listCount - 1].status ? "Nice" : "Naughty");
                break;

            case 2:  // Remove from the list
                displayEntireList(santasList, listCount);
                int index;
                printf("Enter the number of the person to remove: ");
                scanf("%d", &index);
                index--;  // Convert to 0-based index

                if (index >= 0 && index < listCount)
                {
                    removeName(santasList, &listCount, index);
                    file = fopen("Santas_List.txt", "w");  // Open file to overwrite after modification
                    saveListToFile(file, santasList, listCount);
                }
                else
                {
                    printf("Invalid index.\n");
                }
                break;

            case 3:  // View the Entire list
                displayEntireList(santasList, listCount);
                break;

            case 4:  // View the Naughty list
                displayNaughtyList(santasList, listCount);
                break;

            case 5:  // View the Nice list
                displayNiceList(santasList, listCount);
                break;

            case 6:  // Exit
                file = fopen("Santas_List.txt", "w");
                saveListToFile(file, santasList, listCount);
                printf("Data saved to file. Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}