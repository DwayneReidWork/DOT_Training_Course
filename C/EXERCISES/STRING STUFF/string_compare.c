#include <stdio.h>
#include <string.h>

int main() {
    char string1[50];
    char string2[50];

    // Input strings
    printf("Please enter the first string: ");
    scanf("%s", string1);
    printf("Please enter the second string: ");
    scanf("%s", string2);

    //compares ascii?
    /*compares each charachter and stops at the first differece {try apple and applause it will stop at the e and compare there and because e beats a it says apple is the greater string}*/
    int result = strcmp(string1, string2);

    //compare ascii
    if (result > 0) {
        printf("The greater string is: %s\n", string1);
    } else if (result < 0) {
        printf("The greater string is: %s\n", string2);
    } else {
        printf("Both strings are equal.\n");
    }

    return 0;
}
