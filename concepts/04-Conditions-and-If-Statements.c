//Conditional_demo.c
//Author: yazarouz
//Date: 2026/02/22

// Comparison operators:
// Less than: a < b
// Less than or equal to: a <= b
// Greater than: a > b
// Greater than or equal to: a >= b
// Equal to: a == b
// Not equal to: a != b

// Common Mistake: 
// if(a = 5)    Assignment
// if(a == 5)   Comparison

// Conditional statements:
// if: execute code if condition is true
// else: execute code if condition is false
// else if: test another condition if previous was false
// switch: select one of many code blocks to execute

// Syntax - if/else:
/*
if(condition) {
    // code to execute
} else if(otherCondition) {
    // code to execute
} else {
    // code to execute
}
*/

// Syntax - switch:
/*
switch(expression) {
    case x:
        // code block
        break;  // Don't forget break!
    case y:
        // code block
        break;
    default:
        // code block (no break needed)
}
*/

// Ternary Operator:
// variable = (condition) ? valueIfTrue : valueIfFalse;

#include <stdio.h>

int main(){
    // Example 1: Simple if/else
    int x = 10, y = 20;
    
    if(x > y){
        printf("%d is greater than %d!\n", x, y);
    } else {
        printf("%d is greater than %d!\n", y, x);
    }
    // Output: 20 is greater than 10!
    
    // Example 2: if/else if/else
    int age = 17;

    if(age >= 18){
        printf("You are adult!\n");
    } else if(age >= 13){
        printf("You are teenager!\n");
    } else {
        printf("You are kid!\n");
    }
    // Output: You are teenager!

    // Example 3: switch statement
    int weather = 2;  // 1=sunny, 2=rainy, 3=snowy

    switch(weather){
        case 1:
            printf("Do not forget to wear sunglasses!\n");
            break;
        case 2:
            printf("Do not forget to take an umbrella!\n");
            break;
        case 3:
            printf("Do not forget to wear thick clothes!\n");
            break;
        default:
            printf("We do not have enough information about weather!\n");
    }
    // Output: Do not forget to take an umbrella!

    // Example 4: Ternary operator
    int time = 20;
    (time < 18) ? printf("Have a good day.\n") : printf("Have a good night.\n");
    // Output: Have a good night.

    return 0;
}