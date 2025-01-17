#include <stdio.h>

int main() {
    //build initial variables
    float litre_minus = .10; //for bottles under a litre
    float litre_plus = .25; // for bottles over a litre
    int deposited_small_bottles;
    int deposited_big_bottles;
    float total;

    //get bottles less than a litre
    printf("\nHow many bottles do you have less than a litre? ");
    scanf("%d", &deposited_small_bottles);
    //get bottles greater than a litre
    printf("\nHow many bottles do you have greater than or equal to a litre? ");
    scanf("%d", &deposited_big_bottles);

    total = (deposited_small_bottles * litre_minus) + (deposited_big_bottles * litre_plus);

    printf("You entered %d small bottles and %d large bottles. your total refund is $%.2f\n", deposited_small_bottles, deposited_big_bottles, total);

    return 0;
}