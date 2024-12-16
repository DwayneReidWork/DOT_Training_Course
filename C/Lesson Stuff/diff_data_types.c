#include <stdio.h>

int main(){
    int age = 25;
    float salary = 50000.50;
    char grade = 'A';

    printf("Age: %d\n", age); //%d for ints
    printf("Salary: %.2f\n", salary); //%f for floats
    printf("Grade: %c\n", grade); //%c for chard
    
    return 0;
}
//%p for pointers