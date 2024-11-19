#include <stdio.h>

int main() {
    char word_to_copy[] = "Hello World!";  // source string
    char copied_to[50]; // destination stringg

    char *src_ptr = word_to_copy; // Pointer to the source string
    char *dest_ptr = copied_to;  //pointer to destination string

    // Copy characters from word_to_copy to copied_to
    while (*src_ptr != '\0') {
        *dest_ptr = *src_ptr; // copies char
        //increment pointers
        src_ptr++;            
        dest_ptr++;            
    }
    // Null-terminate the destination string
    *dest_ptr = '\0'; 

    //print everything
    printf("Original word: %s\nCopied here: %s\n", word_to_copy, copied_to);

    return 0;
}