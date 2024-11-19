#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    //if scanf doesnt recieve a number 
    if (scanf("%d", &num) !=1 )
    {
        printf("Invalid input. Please enter a valid number.");
    }
    return 0;
}