#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int int1;
    int int2;
 
    printf("Enter first int: ");
    scanf("%d", &int1);
    printf("enter second int: ");
    scanf("%d", &int2);
 
 
    int (*operation[3])(int, int) = {add, subtract, multiply};
    for (int i = 0; i <= 0; i++)
    {
        printf("add: %d\n", operation[i](int1,int2));
        printf("subtract: %d\n", operation[i+1](int1,int2));
        printf("multiply: %d\n", operation[i+2](int1,int2));
    }
    
    return 0;
}