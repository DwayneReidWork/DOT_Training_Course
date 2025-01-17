#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char letter;

void vowel_counter(char* str, int* up_v, int* low_v) 
{
    int upper_vowel = 0;
    int lower_vowel = 0;
    //char letter;

    for (int i = 0; str[i] != '\0'; i++) 
    { 
        letter = str[i]; 

        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        {
            lower_vowel++;
        } 
        else if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') 
        {
            upper_vowel++;
        }
    }
    *up_v = upper_vowel;
    *low_v = lower_vowel;      
}

void consonant_counter(char* str, int* up_c, int* low_c)
{
    int upper_cons = 0 , lower_cons = 0;
    //char letter;
    for (int i = 0; str[i] != '\0'; i++) { 
        letter = str[i];

        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
        {
            continue;
        }

        else if (isalpha(letter))
        {
            if (letter >= 'a' && letter <= 'z') 
            {
                lower_cons++;
            } else if (letter >= 'A' && letter <= 'Z') 
            {
                upper_cons++;
            }
        }
    }
    *up_c = upper_cons;
    *low_c = lower_cons;
}

void special_counter(char* str, int* sp_c)
{
    //char letter;
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        letter = str[i];
        if (ispunct(letter))
        {
            counter++;
        }
    }
    *sp_c = counter;
}

int main()
{
    //declare variables
    int choice, up_v, low_v, up_c, low_c, sp_c;
    //array for user input
    char string_to_count[1000];

    //get user inuput
    printf("Please enter a string you'd like to count vowels and consonants in: ");
    /*fgets reads full line. scanf stops at white space
    stores read chars in string_to_count array --> sizeof(string_to_count) limits read chars up to null terminator from standard input*/
    fgets(string_to_count, sizeof(string_to_count), stdin);
    /*removes new line char and replaces it with nul terminator
    explanation fgets stores "Hello, World!\n\0"
    this line fixes that*/
    string_to_count[strcspn(string_to_count, "\n")] = '\0';   
    while (choice != 7) {
        // Display options menu
        printf("\nChoose an option:\n");
        printf("1. Count vowels\n");
        printf("2. Count consonants\n");
        printf("3. Count special characters\n");
        printf("4. Count all vowels, consonants, and special characters\n");
        printf("5. Count uppercase characters\n");
        printf("6. Count lowercase characters\n");
        printf("7. Exit\n");

        // Get user's choice and handle invalid input
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear the input  so it doesnt loop
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            choice = -1;  // Reset choice to continue looping
        } else {
            system("cls"); 
            printf("Your phrase was: %s\n", string_to_count);

            //call functions to get numbers for switch statement
            vowel_counter(string_to_count, &up_v, &low_v);
            consonant_counter(string_to_count, &up_c, &low_c);
            special_counter(string_to_count, &sp_c);
            
            // Handle the chosen option
            switch (choice) {
                case 1:
                    printf("Total number of vowels: %d\n", up_v+low_v);
                    break;
                case 2:
                    printf("Total number of consonents: %d\n", up_c+low_c);
                    break;
                case 3:
                    printf("Total number of special charachters: %d\n", sp_c);
                    break;
                case 4:
                    printf("Total number of vowels: %d\n", up_v+low_v);
                    printf("Total number of consonents: %d\n", up_c+low_c);
                    printf("Total number of special charachters: %d\n", sp_c);
                    break;
                case 5:
                    printf("Total number of uppercase vowels: %d\n", up_v);
                    printf("Total number of uppercase consonents: %d\n", up_c);
                    break;
                case 6:
                    printf("Total number of lowercase vowels: %d\n", low_v);
                    printf("Total number of lowercase consonents: %d\n", low_c);
                    break;
                case 7:
                    printf("Goodbye.\n");
                    break;
                default:
                    printf("Invalid option. Please enter a number between 1 and 7.\n");
                    main();
            }    
        }
    return 0;
    }
}