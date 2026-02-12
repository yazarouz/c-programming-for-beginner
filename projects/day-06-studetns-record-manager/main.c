// ============================================================
// Student Grade Tracker & Analyzer
// Author: yazarouz
// Date: 2026/02/05
// Description:
//   A console application that manages student records including:
//   • Student ID and name
//   • Three subject grades per student
//   • Automatic average calculation
//   • Display of individual/all records
//   • Identification of top-performing student by average
//   Note: Uses basic input handling (scanf) — consider fgets for production.
// ============================================================

#include <stdio.h>

#define name_lenth 100
#define max_students 5

typedef struct{
    int students_id;
    float grades[3];
    float ave;
    char name[name_lenth];
}Students;
float claculator_ave(float grades[3]){
    int sum = 0;
    for(int i = 0 ; i < 3 ; i++){
        sum += grades[i];
    }
    float ave = sum / 3;
    return ave;
}
void add_stu(Students *s){
    printf("enter students name: ");
    scanf("%s" , s->name);

    printf("enter students id: ");
    scanf("%d" , &s->students_id);

    printf("enter 3 grades: ");
    for(int i = 0 ; i < 3 ; i++){
        scanf("%f" , &s->grades[i]);
    }

    s->ave = claculator_ave(s->grades);
    printf("students add successfully!\n\n");
}

void display_each(const Students *s){
    printf("Name: %s  |Id: %d  |Grades: %.1f , %.1f , %.1f  |Ave: %.2f  \n" , 
            s->name , s->students_id ,
            s->grades[0] , s->grades[1] , s->grades[2] , 
            s->ave);
}

void display_all(const Students students[] , int count){
    printf("\n---all sudents ---\n");
    for(int i = 0 ; i < count ; i++){
        printf("%d . " , i + 1);
        display_each(&students[i]);
    }
}

float top_ave(const Students students[] , int count){
    int top_index = 0;
    for(int i = 1; i < count ; i++){
        if(students[i].ave > students[top_index].ave){
            top_index = i;
        }
    }
    return top_index;
}
int main(){
    Students students[max_students];
    int count = 0 ;

    add_stu(&students[0]);
    count ++;

    add_stu(&students[1]);
    count ++;

    add_stu(&students[2]);
    count++;

    display_all(students , count);

    int top_index = top_ave(students, count);
    printf("\nTop Student:\n");
    display_each(&students[top_index]);
    
    printf("end program");
    return 0;    
}