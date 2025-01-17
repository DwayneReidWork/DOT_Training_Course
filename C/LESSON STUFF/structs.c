#include <stdio.h>
#include <string.h>

// Define the Student struct
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Initialize student1
    struct Student student1;
    strcpy(student1.name, "Alice");
    student1.age = 20;
    student1.gpa = 3.8;

    // Initialize student2
    struct Student student2 = {"Bob", 22, 3.5};

    // Print details of student1
    printf("Student 1:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n\n", student1.gpa);

    // Print details of student2
    printf("Student 2:\n");
    printf("%s is %d years old and their GPS is %.2f.\n", student2.name, student2.age, student2.gpa);
    return 0;
}
