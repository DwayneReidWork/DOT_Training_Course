#include <stdio.h>
#include <string.h>

// Define the Student struct
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Declare and initialize a Student
    struct Student student1;
    strcpy(student1.name, "Alice");
    student1.age = 20;
    student1.gpa = 3.8;

    // Pointer to the Student struct
    struct Student *ptr;
    ptr = &student1;

    // Access and modify using the pointer
    printf("GPA: %.2f\n", ptr->gpa); // Access GPA using pointer
    ptr->age = 21;                   // Modify age using pointer
    printf("Updated Age: %d\n", ptr->age);

    // Declare an array of Student structs for a class
    struct Student class[30];

    // Example of assigning values to one of the students in the array
    strcpy(class[0].name, "Bob");
    class[0].age = 22;
    class[0].gpa = 3.5;

    // Print details of the first student in the class array
    printf("\nClass[0] Details:\n");
    printf("Name: %s\n", class[0].name);
    printf("Age: %d\n", class[0].age);
    printf("GPA: %.2f\n", class[0].gpa);

    return 0;
}