#include <stdio.h>

int main() {
    //the string ALLOWS for up to 10 chars but because we're only using 8 we have to add a null charachter
    char name[10] = "CProgram";
    name[8] = '\0';
    // %s is for strings %c for chars
    printf("Name: %s\n", name);
    return 0;
}