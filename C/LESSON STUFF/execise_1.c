#include <stdio.h>

int main()
{
    float num;
    int result;

    do
    {
        printf("Enter a floating number: ");
        result = scanf("%f", &num);
        //result returns the number of variables it recieves as input.
        if (result != 1)
        {
            printf("Invalid input. Please Try again.\n");
            //get char is a buffer. This while loops through everything in it and while its not empty itll run.
            while (getchar() != '\n');
        }
    //while you have something in the buffer print the following statement
    } while (result != 1);

    printf("You entered %.2f", num);
    return 0;
}