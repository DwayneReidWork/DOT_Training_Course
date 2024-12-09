#include <stdio.h>
#include <string.h>

// Define the Date struct
struct Date {
    int day;
    int month;
    int year;
};

// Define the Student struct
struct Student {
    char name[50];
    int age;
    float gpa;
    struct Date enrollmentDate;
};

int main() {
    // Declare and initialize a Student
    struct Student student1;
    strcpy(student1.name, "Alice");
    student1.age = 20;
    student1.gpa = 3.8;

    // Set the enrollment date
    student1.enrollmentDate.day = 15;
    student1.enrollmentDate.month = 8;
    student1.enrollmentDate.year = 2021;

    // Print student details
    printf("Student Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);
    printf("Enrollment Date: %02d/%02d/%d\n", student1.enrollmentDate.month, student1.enrollmentDate.day, student1.enrollmentDate.year);

    return 0;
}