#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "naughty_or_nice_functions.h"

// Max size for lists
#define MAX_LIST_SIZE 100

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
                    saveListToFile(santasList, listCount);
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
                saveListToFile(santasList, listCount);
                printf("Data saved to file. Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}