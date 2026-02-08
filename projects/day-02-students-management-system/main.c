// =============================================================================
// Author: yazarouz
// Date: 2026-02-01
// Description: Simple student management system for beginners (struct + array)
// =============================================================================

#include <stdio.h>
#include <string.h>

#define max_students 3

typedef struct{
    char name[100];
    int students_id;
    float grade;
}Students;

void add_students(Students *s){
    printf("enter students name: ");
    fgets(s->name , sizeof(s->name) , stdin);

    printf("enter student id: ");
    scanf("%d" , &s->students_id);
    getchar();

    printf("enter student`s grade: ");
    scanf("%f" , &s->grade);
    getchar();
}

int menu(){
    int flag;
    printf("please selec a option to search: \n");
    printf("1 . search by name\n");
    printf("2 . search by students id\n");
    scanf("%d" , &flag);
    return flag;
}

int search_by_name(const Students *s , int *index){
    getchar();
    printf("enter name for search: ");
    char se_name[100];  //searched name
    fgets(se_name , sizeof(se_name) , stdin);

    for(int i = 0 ; i < max_students ; i++){
        if(strcmp(se_name , s[i].name) == 0){
            *index = i;
            return 1;
        }
    }
    
    return 0;
}

int search_by_id(const Students *s , int *index){
    int se_id;  //searched id
    printf("enter id for search: ");
    scanf("%d" , &se_id);

    for(int i = 0 ; i < max_students ; i++){
        if(se_id == s[i].students_id){
            *index = i;
            return 1;
        }
    }

    return 0;
}

void display_students(const Students *s){
    printf("Name : %s   |Student`s id: %d   |grades: %f\n" , 
            s->name , s->students_id , s->grade
    );
}

int main(){
    Students students[max_students];
    printf("=========================================");
    printf("--- simple students management system ---");
    printf("=========================================\n");

    add_students(&students[0]);

    add_students(&students[1]);

    add_students(&students[2]);

    int flag = menu();

    if(flag == 1){
        int result;
        int index;
        result = search_by_name(students , &index);

        if(result == 1){
            printf("students successfully find!\n");

            display_students(&students[index]);
        }
        else{
            printf("there isn`t student with this name!\n");
        }
    }
    else if(flag == 2){
        int result;
        int index;
        result = search_by_id(students , &index);

        if(result == 1){
            printf("studens successfully find!\n");

            display_students(&students[index]);
        }
        else{
            printf("there isn`t students whit this id!\n");
        }
    }
    else{
        printf("Error : Invalid option please choose option between 1 or 2");
    }
}