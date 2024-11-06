#include <stdio.h>

//function declaration
int add(int a, int b);

int main (){
    int num1 = 10;
    int num2 =20;
    int result;

    //call the add function
    result = add(num1, num2);

    //display result
    printf("The sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

//Function definition
int add(int a, int b){
    return a+b; //return the sum of a and b
}