#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    unsigned int a, b;
    printf("Enter your values for a and b (separated by a space): ");
    scanf("%d %d", &a, &b);
    
    printf("& = %u\n| = %u\n^ = %u\nBitwise NOT of %d (~num1) = %u\nBitwise NOT of %d (~num2) = %u\n", a & b, a | b, a ^ b, a, ~a, b, ~b);

    return 0;
}
