#include <stdio.h>
#include <string.h>

// Define the Book struct
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    struct Book books[3];  // Array to store 3 books

    // Loop to get input for 3 books
    for (int i = 0; i < 3; i++) {
        // Input book title
        printf("Please enter your book title: ");
        scanf(" %[^\n]%*c", books[i].title); // Notice the space before %[^\n]

        // Input book author
        printf("Please enter your book author: ");
        scanf(" %[^\n]%*c", books[i].author); // Space before %[^\n] to skip leading whitespace

        // Input book pages
        printf("Please enter your book page length: ");
        scanf("%d", &books[i].pages); // Use & to pass the address

        // Input book price
        printf("Please enter your book price: ");
        scanf("%f", &books[i].price); // Use & to pass the address
    }

    // Print the book details
    printf("\nBook Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: $%.2f\n\n", books[i].price); // Print price with 2 decimal places
    }

    return 0;
}