#include <stdio.h>

int main() {
    int var = 10; //declare an int variable
    int *ptr; //declare a pointer to an int.
    ptr = &var; // initialize pointer to the address of var (ampersand allows that)

    //displays the values
    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", (void*)&var);
    printf("Value stored in ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr); //dereference ptr to get vars value

    return 0;
}