#include <stdio.h>

int main() {
    int numbers[5]; //declare an array of 5
    int i;

    printf("Enter 5 integers: \n");
    for (i=0; i<5; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &numbers[i]); //store inputs in the array
    }
    //Display entered numbers
    printf("You entered:\n");
    for(i=0; i<5; i++){
        printf("Number %d: %d\n", i+1, numbers[i]);
    }

    return 0;
}