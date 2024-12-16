#include <stdio.h>

int main()
{
    int numbers[10]; //static allocation for 5 variables
    for (int i = 0; i < 10; i++) {
        numbers[i] = i+1;
    }
    for (int i=0;i < 5; i++) {
        printf("numbers[%d]=%d\n", i, numbers[i]);
    }

    return 0;
}