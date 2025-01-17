#include <stdio.h>

int simpleHash(int key, int size)
{
    return key % size;
}

int main()
{
    int key = 12345;
    printf("Hash value: %d\n", simpleHash(key, 100));
}