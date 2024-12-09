#include <stdio.h>  // Standard input/output library
#include <string.h>  // Library for string manipulation functions like strcpy

// Define the Date struct to represent a date (day, month, and year)
struct Date {
    int day;    // Day of the month (e.g., 28)
    int month;  // Month of the year (e.g., 11 for November)
    int year;   // Year (e.g., 2024)
};

// Define the Holiday struct to store details of a holiday
struct Holiday {
    char name[50];      // Array of characters to store the holiday name (e.g., "Thanksgiving")
    char location[50];  // Array of characters to store the location of the holiday (e.g., "Home")
    struct Date eventDate;  // An instance of Date struct to store the event's date
};

int main() {
    // Declare a variable of type Holiday to store details of Thanksgiving
    struct Holiday uInputHoliday;

    printf("Please enter a holiday: ");
    scanf(" %[^\n]%*c", uInputHoliday.name);

    printf("Please enter the location of the holiday: ");
    scanf(" %[^\n]%*c", uInputHoliday.location);

    printf("Please enter the date (MM DD YYYY): ");
    scanf("%d %d %d", &uInputHoliday.eventDate.month, &uInputHoliday.eventDate.day, &uInputHoliday.eventDate.year);
    // Print the details of the holiday (Thanksgiving)
    // Print the holiday name
    printf("Holiday: %s\n", uInputHoliday.name);
    
    // Print the holiday location
    printf("Location: %s\n", uInputHoliday.location);
    
    // Print the event date, formatted as "DD/MM/YYYY"
    printf("Event Date: %02d/%02d/%d\n", 
           uInputHoliday.eventDate.month, 
           uInputHoliday.eventDate.day, 
           uInputHoliday.eventDate.year);

    return 0;  // Return 0 to indicate successful program execution
}