#include <stdio.h>

//create an array then change a single letter in it

int main() {
   char my_first_program[] = "Hello World";
   printf("%s\n", my_first_program);
   my_first_program[0] = 'J';
   printf("%s\n", my_first_program);
   return 0;
}