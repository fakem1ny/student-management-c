#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

#endif