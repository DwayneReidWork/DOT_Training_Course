#include <stdio.h>

int main(){
    int num1, num2;
    int sum, difference, product, quotient, remainder;

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);

    sum = num1+num2;
    difference = num1-num2;
    product = num1*num2;
    quotient = num1/num2;
    remainder = num1%num2;

    printf("\n---Arithmatic Operations---\n");
    printf("Sum: %d + %d = %d\n", num1, num2, sum);
    printf("Difference: %d - %d = %d\n", num1, num2, difference);
    printf("Product: %d * %d = %d\n", num1, num2, product);
    printf("Quotient: %d / %d = %d\n", num1, num2, quotient);
    printf("Remainder: %d %% %d = %d\n", num1, num2, remainder); //first percent sign is an escape char

    return 0;
}