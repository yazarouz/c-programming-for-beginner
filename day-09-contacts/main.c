/**
 * ============================================================================
 *                        SIMPLE PHONEBOOK APPLICATION
 * ============================================================================
 * 
 * Description: A simple phonebook application written in C that allows users
 *              to manage contacts including adding, searching, displaying,
 *              and saving contacts to a file.
 * 
 * Features:
 *   - Add multiple contacts
 *   - Search contacts by name
 *   - Display all contacts
 *   - Save and load contacts from file
 *   - Interactive menu-based interface
 * 
 * Author: yazarouz
 * Date: February 12, 2026
 * 
 * File: phonebook.c
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define PHONE_LENGTH 15
#define MAX_CONTACTS 20
#define FILENAME "phonebook.txt"

typedef struct{
    char name[MAX_LENGTH];
    char phone[PHONE_LENGTH];
}Contact;

int load_contacts(Contact list[]){
    FILE *file = fopen(FILENAME , "r");

    if(file == NULL){
        printf("Error : Can not open file\n");
        return 0;
    }

    int count = 0;
    while(count < MAX_CONTACTS && 
        fscanf(file , " %[^|]|%[^\n]" , list[count].name , list[count].phone) == 2)
    {
        count ++;
    }

    fclose(file);
    printf("File successfully loaded!\n");
    return count;
}

void add_contact(Contact *c , int *count){
    printf("Please enter contact`s name: ");
    fgets(c->name, MAX_LENGTH , stdin);
    c->name[strcspn(c->name , "\n")] = '\0';

    printf("Please enter %s`s phone number: " , c->name);
    fgets(c->phone , PHONE_LENGTH , stdin);
    c->phone[strcspn(c->phone , "\n")] = '\0';

    (*count)++;
    printf("Contact successfully added!\n");
}

void search_contact(Contact list[] , int count){
    char searched_name[MAX_LENGTH];
    printf("Enter name to search: ");
    fgets(searched_name , MAX_LENGTH , stdin);
    searched_name[strcspn(searched_name , "\n")] = '\0';

    int flag = 0;
    for(int i = 0 ; i < count ; i++){
        if(strcmp(searched_name , list[i].name) == 0){
            printf("Contact successfully find!\n");
            printf("%s : %s\n" , list[i].name , list[i].phone);
            flag = 1;
        }
    }

    if(flag != 1){
        printf(" '%s' not found in contacts!\n" , searched_name);
    }
}

void show_all_contacts(Contact list[] , int count){
    for(int i = 0 ; i < count ; i++){
        printf("\n %d . %s : %s\n" , i + 1 , list[i].name , list[i].phone);
        printf("--------------------------------------\n");
    }
}

void save_file(Contact list[] , int count){
    FILE *file = fopen(FILENAME , "w");
    int flag = 0;
    if(file == NULL){
        printf("Error : can not open file!\n");
        flag = 1;
    }

    if(flag != 1){
        for(int i = 0 ; i < count ; i++){
            fprintf(file , "%s|%s\n" , list[i].name , list[i].phone);
        }
        
        fclose(file);
        printf("File successfully saved!\n");
    }
}

void menu(){
    printf("\n--- Show Menu To User ---\n");
    printf("1 . Add contacts\n");
    printf("2 . Search contact\n");
    printf("3 . Show all contacts\n");
    printf("4 . Exit\n");
    printf("Your choice: ");
}

int main(){
    Contact contacts[MAX_CONTACTS];

    printf("=============================\n");
    printf("----- Simple phonebook -----\n");
    printf("============================\n");

    int count = load_contacts(contacts);
    show_all_contacts(contacts , count);

    int flag;
    do{
        int count_contact;          //count of contacts
        menu();  
        scanf("%d" , &flag);        //select option
        getchar();

        switch(flag){
        case 1: 
            printf("How many contact do you want add: ");
            scanf("%d" , &count_contact);
            getchar();
            if(count_contact > MAX_CONTACTS - count){
                printf("Error : Overflow!\n");
            }else{
                for(int i = 0 ; i < count_contact ; i++){
                    add_contact(&contacts[count] , &count);
                }
            }
            break;
        case 2:
            search_contact(contacts , count);
            break;
        case 3:
            show_all_contacts(contacts , count);
            break;
        case 4:
            save_file(contacts , count);
            show_all_contacts(contacts , count);
            printf("Goodbye! list successfully updated!\n");
            break;
        default:
            printf("Invalid option: please select option between 1-4\n");
            break;
        }
    }while(flag != 4);

    return 0;
}