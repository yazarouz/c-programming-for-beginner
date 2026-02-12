// ============================================================
// Student Grade Sorter
// Author: yazarouz
// Date: 2026/02/04
// Description:
//   A console application that collects names and grades for
//   5 students, sorts them in descending order by grade using
//   bubble sort algorithm, and displays the ranked list.
//   Features safe input handling with fgets() and newline cleanup.
// ============================================================

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 
#define MAX_STUDENTS 5

typedef struct {
    char name[MAX_LENGTH];
    float grade;
} Student; 

void add_student(Student *s) {
    printf("Please enter name: ");
    fgets(s->name, MAX_LENGTH, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    
    printf("Please enter grade for %s: ", s->name);
    scanf("%f", &s->grade);
    getchar();
}

void sort_students(Student students[]) {
    for (int i = 0; i < MAX_STUDENTS - 1; i++) {
        for (int j = 0; j < MAX_STUDENTS - i - 1; j++) { 
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students(const Student students[]) {
    printf("\n--- Sorted Student List ---\n"); 
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%d. %s's grade: %.2f\n", i + 1, students[i].name, students[i].grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    
    printf("========================================\n");
    printf("   Student Sorter by yazarouz\n");
    printf("========================================\n\n");
    
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student #%d:\n", i + 1);
        add_student(&students[i]);
        printf("\n");
    }
    
    sort_students(students);
    print_students(students);
    
    return 0;
}