#include <stdio.h>

int main() {
    int num1;
    int num2;
    char word[50];
    
    printf("Enter a word and two numbers (seperated by spaces): ");
    scanf("%s %d %d", word, &num1, & num2);
    printf("You entered numbers %d and %d and the word '%s'\n", num2, num1, word);
    
    return 0;
}
