#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

void addStudent(Student *students, int index, int id, const char *name, int age, float gpa) {
    students[index].id = id;
    strcpy(students[index].name, name);
    students[index].age = age;
    students[index].gpa = gpa;
}

int searchStudent(Student *students, int n, int targetId) {
    for (int i = 0; i < n; i++) {
        if (students[i].id == targetId) return i;
    }
    return -1;
}

void displayStudent(Student student) {
    printf("ID: %d\nName: %s\nAge: %d\nGPA: %.2f\n", student.id, student.name, student.age, student.gpa);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) return 1;

    for (int i = 0; i < n; i++) {
        int id, age;
        float gpa;
        char name[50];
        printf("Enter ID, Name, Age, GPA for student %d:\n", i + 1);
        scanf("%d %s %d %f", &id, name, &age, &gpa);
        addStudent(students, i, id, name, age, gpa);
    }

    int searchId;
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);

    int index = searchStudent(students, n, searchId);
    if (index != -1) displayStudent(students[index]);
    else printf("Student not found.\n");

    free(students);
    return 0;
}
