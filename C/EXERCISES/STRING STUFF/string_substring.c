#include <stdio.h>
#include <string.h>

int main() {
    char string1[50] = "This is my string. Hello!";
    char search_word[50];

    // Input strings
    printf("Please enter a word to find in the string: ");
    scanf("%s", search_word);

    //gets location of the pointer
    char *location = strstr(string1, search_word);

    // Check if search_word is in string1
    if (strstr(string1, search_word) != NULL) {
        //use position of pointer to help calculate the position in the array or chars
        int position = location - string1;
        printf("The word '%s' is found in the string '%s' was found at position %d.\n", search_word, string1, position);
    } else {
        printf("Your word is not found in the string.\n");
    }

    return 0;
}
