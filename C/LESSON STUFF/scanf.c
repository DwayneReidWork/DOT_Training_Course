#include <stdio.h>

int main() {
    int age;
    char name[50];
    
    // Prompt user for input
    printf("Enter your name and age: ");
    
    // Corrected scanf format: name first, then age
    scanf("%s %d", name, &age);
    
    // Correct printf statement
    printf("Hello %s, you are %d years old.\n", name, age);
    
    return 0;
}
