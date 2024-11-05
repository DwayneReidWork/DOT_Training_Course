#include <stdio.h>

int main(){
    int i =1;

    do{ //do <this block of code> while <this condition is met>
        printf("Number: %d\n", i);
        i++;
    } while(i<=5);

    return 0;
}