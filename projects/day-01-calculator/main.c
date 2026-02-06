//author: yazarouz || date : 2026/01/31
//A modular calculator to practice problem decomposition
#include <stdio.h>
void menu(){
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Power\n");
    printf("7. Exit\n");
}

void Addition(){
    int a , b;
    printf("enter first number : ");
    scanf("%d" , &a);
    printf("enter second number: ");
    scanf("%d" , &b);

    printf("sum is: %d\n" , a + b);
}

void Subtraction(){
    int a , b;
    printf("enter first number: ");
    scanf("%d" , &a);
    printf("enter second number: ");
    scanf("%d" , &b);
    
    printf("sum i: %d" , a - b);
}

void Multiplication(){
    int a , b;
    printf("enter first number: ");
    scanf("%d" , &a);
    printf("enter second number: ");
    scanf("%d" , &b);

    printf("sum is: %d" , a * b);
}

void Division(){
    int a , b;
    printf("enter first number: ");
    scanf("%d" , &a);
    printf("enter second number: ");
    scanf("%d" , &b);

    if(b == 0){
        printf("Errro: division by zero!");
    }
    else
        printf("sum is: %d" , a / b);
}

int Factorial(int a){
    if(a == 1) return 1;
    return a * Factorial(a - 1); 
}

void Power(){
    int a , b , sum = 1;
    printf("enter bass: ");
    scanf("%d" , &a);
    printf("enter exponer: ");
    scanf("%d" , &b);
    if(b < 0) printf("Error: negative exponet are not supprted in this version!");
    else{
        for(int i = 0 ; i < b ; i++){
            sum *= a;
        }
        printf("sum is: %d" , sum);
    } 
}
int main(){
    printf("=== simple claculator ===\n");
    while(1){
        int flag;
        menu();
        printf("please choose a option: ");
        scanf("%d" , &flag);
        switch(flag){
        int a , sum;
            case 1:
                Addition();
                break;
            case 2: 
                Subtraction();
                break;
            case 3:
                Multiplication();
                break;
            case 4:
                Division();
                break;
            case 5: 
                printf("enter non-negarive number: ");
                scanf("%d" , &a);

                if(a < 0) printf("Error: factorial are not difined to negative nubmer!");
                sum = Factorial(a);
                
                printf("sum is: %d" , sum);
                break;
            case 6:
                Power();
                break;
            case 7:
                printf("good by!");
                return 0;
            default:
                printf("invalid option please select option between 1 ---> 7 \n");
                break;
            }
        printf("==================================================\n");
   }
}