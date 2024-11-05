#include <stdio.h>

int main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if(num > 0){
        printf("You entered a positive number.");
    }
    else if (num < 0){ // <--must include the statement in parenthesis
        printf("You entered a negative number.");
    }
    else{
        printf("You entered 0.");
    }
    return 0;
}