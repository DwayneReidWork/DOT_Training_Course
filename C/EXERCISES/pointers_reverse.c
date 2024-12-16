#include <stdio.h>

void reverseString(char *str) {
    //pointer to the end of the word
    char *end = str;
    //while pointer isn't at the end of the word keep going up
    while (*end != '\0') {
        end++;
    }
    //once you reach the null charachter go back one for the last letter
    end--;

    while (str < end) {
        char temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[] = "Hello"; // Use a character array to allow modification
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

//THIS USES INDEXING SO IT WORKS BUT DOESNT ANSWER THE QUESTION
// int main() {
//     char *ptr = "Hello"; 
//     char new_array[50];
//     int i = 0;
//     int j = 0;  // j will be the index for new_array

//     while (ptr[i] != '\0') {
//         i++;
//     }
    
//     while (i > 0) {
//         i--;  // reverse
//         new_array[j] = ptr[i];  // reverse copy
//         j++;  // Increment the index for new_array
//     }
//     new_array[j] = '\0';  // null terminate at index

//     printf("Reversed string: %s\n", new_array);

//     return 0;
// }