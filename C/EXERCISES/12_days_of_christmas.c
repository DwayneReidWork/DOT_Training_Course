#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* day;
    char* gift;
} DayOfSong;

int main() {
    // Create instances for each day
    DayOfSong day1 = {"first", "A partridge in a pear tree."};
    DayOfSong day2 = {"second", "Two Turtle Doves."};
    DayOfSong day3 = {"third", "Three French Hens."};
    DayOfSong day4 = {"fourth", "Four Calling Birds."};
    DayOfSong day5 = {"fifth", "FIIIIIIIIIIIVE GOLDEN RINGS!!!!"};
    DayOfSong day6 = {"sixth", "Six Geese a-laying."};
    DayOfSong day7 = {"seventh", "Seven swans a-swimming."};
    DayOfSong day8 = {"eighth", "Eight Maids a-milking."};
    DayOfSong day9 = {"ninth", "Nine ladies dancing."};
    DayOfSong day10 = {"tenth", "Ten lords a-leaping."};
    DayOfSong day11 = {"eleventh", "Eleven pipers piping."};
    DayOfSong day12 = {"twelfth", "Twelve Drummers Drumming."};

    // Create an array to store the days
    DayOfSong* numbers[13] = {NULL, &day1, &day2, &day3, &day4, &day5, &day6, &day7, &day8, &day9, &day10, &day11, &day12};

    // Get user input
    char uInput[10];
    printf("Please enter which verse you'd like to hear or enter 'all' to hear the entire song: ");
    fgets(uInput, sizeof(uInput), stdin);
    uInput[strcspn(uInput, "\n")] = 0; // Remove newline character

    if (strcmp(uInput, "all") == 0) {
        for (int day = 1; day <= 12; day++) {  // Loop through days 1 to 12
            char* gift_list[12];
            int count = 0;
            for (int x = day; x > 1; x--) {  // Collect gifts in reverse order
                gift_list[count++] = numbers[x]->gift;
            }

            printf("On the %s day of Christmas\nmy true love gave to me:\n", numbers[day]->day);
            for (int i = count - 1; i >= 0; i--) {
                printf("%s\n", gift_list[i]);
            }
            printf("and a partridge in a pear tree.\n\n");
        }
    } else {
        int day;
        if (sscanf(uInput, "%d", &day) == 1) {
            if (day >= 1 && day <= 12) {
                char* gift_list[12];
                int count = 0;
                for (int x = day; x > 1; x--) {
                    gift_list[count++] = numbers[x]->gift;
                }

                printf("On the %s day of Christmas.\nMy true love gave to me\n", numbers[day]->day);
                for (int i = count - 1; i >= 0; i--) {
                    printf("%s\n", gift_list[i]);
                }
                printf("and a partridge in a pear tree.\n");
            } else {
                printf("Please enter a number between 1 and 12 or 'all'.\n");
            }
        } else {
            printf("Invalid input. Please enter a number or 'all'.\n");
        }
    }

    return 0;
}