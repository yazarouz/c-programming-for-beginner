//Author : yazarouz     || date : 2026/02/14
/*
 * Simple Library Management System
 * 
 * A console-based C program for managing a small library.
 * Features: Add/Search/Borrow/Return/Delete books with file persistence.
 * Data is stored in 'library.txt' using pipe-delimited format.
 */

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define TITLE_LENGHT 100
#define AUTHOR_LENGTH 100
#define FILENAME "library.txt"

typedef struct {
    char title[TITLE_LENGHT];
    char author[AUTHOR_LENGTH];
    int book_id;
    int status;         //if borrowed = 0
}Library;

int loaded_file(Library *b){
    FILE *file = fopen(FILENAME , "r");

    if(file == NULL){
        printf("Error : can not open file\n");
        return 0;
    }

    int count = 0;
    while(count < MAX_BOOKS && 
    fscanf(file , "%[^|]|%[^|]|%d|%d\n" , b[count].title , b[count].author ,
    &b[count].book_id , &b[count].status) == 4){
        count++;
    }
    
    fclose(file);
    printf("Loaded file successfully!\n");
    return count;
}

void menu(){
    printf("1 . Add book\n");
    printf("2 . Borrow book\n");
    printf("3 . Return book\n");
    printf("4 . Search book(by title)\n");
    printf("5 . Search book(by author)\n");
    printf("6 . Display all book\n");
    printf("7 . Delete book\n");
    printf("8 . Exit\n");
    printf("Your choice : ");
}

void add_book(Library *b , int *count){
    printf("Enter title : ");
    fgets(b->title , TITLE_LENGHT , stdin);
    b->title[strcspn(b->title , "\n")] = '\0';

    printf("Enter author: ");
    fgets(b->author , AUTHOR_LENGTH , stdin);
    b->author[strcspn(b->author , "\n")] = '\0';

    printf("Enter book id: ");
    scanf("%d" , &b->book_id);
    getchar();

    b->status = 1;

    printf("Book successfully added!\n");
    (*count)++;
}

void display_each(const Library *b){
    int index = 1;
    printf("\n%d .Title : %s  |Author : %s  | Book ID : %d  | Status : %d\n" ,
    index ,
    b->title ,
    b->author ,
    b->book_id ,
    b->status ? "AVAILABLE" : "BORROWED"
    );
    
    printf("===========================================================================\n");
    index ++;
}

void borrow_book(Library list[] , int  count){
    char book[TITLE_LENGHT];
    printf("Enter title : ");
    fgets(book , TITLE_LENGHT , stdin);
    book[strcspn(book , "\n")] = '\0';

    int flag = 0 ;
    for(int i = 0 ; i < count ; i++){
        if(strcmp(book , list[i].title) == 0){
            list[i].status = 0;

            printf("Book successfully borrowed!\n");
            display_each(&list[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Unfortunately '%s' not found.\n" , book);
    }
}

void return_book(Library list[] , int count){
    char book[TITLE_LENGHT];
    printf("Enter title: ");
    fgets(book , TITLE_LENGHT , stdin);
    book[strcspn(book , "\n")] = '\0';

    int flag = 0 ;
    for(int i = 0 ; i < count ; i++){
        if(strcmp(book , list[i].title) == 0){
            printf("Book successfully returned!\n");
            list[i].status = 1;
            display_each(&list[i]);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("Unfortunately '%s' not found!\n" , book);
    }
}

void search_by_title(const Library list[] , int count){
    char book[TITLE_LENGHT];
    printf("Enter title to search: ");
    fgets(book , TITLE_LENGHT , stdin);
    book[strcspn(book , "\n")] = '\0';

    int flag = 0;
    int index = 1;
    for(int i = 0 ; i < count  ; i++){
        if(strcmp(book , list[i].title) == 0){
            printf("\n%d . Book successfully found!\n" , index);
            display_each(&list[i]);
            flag = 1;
            index++;
        }
    }
    
    if(flag == 0){
        printf("Unfortunately '%s' not found!\n" , book);
    }
}

void search_by_author(const Library list[] , int count){
    char book[AUTHOR_LENGTH];
    printf("enter book`s author to search: ");
    fgets(book , AUTHOR_LENGTH , stdin);
    book[strcspn(book , "\n")] = '\0';

    int flag = 0 ;
    int index = 1;
    for(int i = 0 ; i < count ; i++){
        if(strcmp(book , list[i].author) == 0){
            printf("\n%d . Book successfully found!\n" , index);
            display_each(&list[i]);
            flag = 1;
            index++;
        }
    }
     if(flag == 0){
        printf("Unfortunately '%s' not found!\n" , book);
    }
}

void display_all(const Library list[] , int count){
    for(int i = 0 ; i < count ; i++){
        display_each(&list[i]);
    }
}

void save_file(const Library list[] , int count){
    FILE *file = fopen(FILENAME , "w");

    if(file == NULL){
        printf("Erroe : file can not open!\n");
        return;
    }

    for(int i = 0 ; i < count ; i++){
        fprintf(file , "%s|%s|%d|%d\n" , 
            list[i].title , list[i].author , list[i].book_id , list[i].status);
    }

    fclose(file);
    printf("File successfully saved!\n");
}

void delete_book(Library list[] , int count){
    char del_book[TITLE_LENGHT];
    printf("Which book you want delete:(enter boook name) ");
    fgets(del_book , TITLE_LENGHT , stdin);
    del_book[strcspn(del_book , "\n")] = '\0';

    int index;
    for(int i = 0 ; i < count ; i++){
        if(strcmp(del_book , list[i].title) == 0){
            index = i;
            break;
        }
    }

    for(int i = index ; i < count ; i++){
        list[i] = list[i + 1];
    }
    
    count --;
    printf("Book delete successfully!\n");
}

int main(){
    printf("=================================\n");
    printf("----- Simple Library System -----\n");
    printf("=================================\n");

    Library book[MAX_BOOKS];
    int count = loaded_file(book);
    display_all(book , count);

    int flag = 0;
    do{
        menu();
        scanf("%d" , &flag);
        getchar();

        switch(flag){
            int new_book = 0;
            case 1:{
                printf("How many book you want to add: ");
                scanf("%d" , &new_book);
                getchar();

                if(new_book > MAX_BOOKS - count){
                    printf("Error : overflow!\n");
                }else{
                    for(int i = 0 ; i < new_book ; i++){
                        add_book(&book[count] , &count);
                    }
                }
            }
                break;
            case 2:
                borrow_book(book , count);
                break;
            case 3:
                return_book(book , count);
                break;
            case 4:
                search_by_title(book , count);
                break;
            case 5:
                search_by_author(book , count);
                break;
            case 6:
                display_all(book , count);
                break;
            case 7:{
                display_all(book ,count);
                delete_book(book , count);
                display_all(book ,count);
                break;
            }
            case 8:
                save_file(book , count);
                printf("Goodbye! list successfully updated!\n");
                break;
            default:
                printf("Invalid option! please select option between 1-7\n");
                break;
        }
    }while(flag != 7);

    return 0;
}