#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    printf("Enter ID: ");
    scanf("%d", &students[*count].id);
    getchar();
    printf("Enter Name: ");
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);
    (*count)++;
}

void displayStudents(Student students[], int count) {
    printf("\n--- Student List ---\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void saveToFile(Student students[], int count) {
    FILE *f = fopen("data.txt", "w");
    for(int i = 0; i < count; i++) {
        fprintf(f, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    fclose(f);
    printf("Data saved to file.\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *f = fopen("data.txt", "r");
    if(f == NULL) return;
    while(fscanf(f, "%d,%49[^,],%f\n", &students[*count].id, students[*count].name, &students[*count].gpa) != EOF) {
        (*count)++;
    }
    fclose(f);
}