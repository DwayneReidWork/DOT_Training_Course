#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    unsigned int num;
    int multiply;
    int divide;

    printf("Enter a number: ");
    scanf("%u", &num);
    
    multiply = num << 1;
    divide = num >> 1;

    printf("Original number: %u\nMultiplied: %u\nDivided: %u\n",num, multiply, divide);

    return 0;
}