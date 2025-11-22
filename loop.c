// loops_demo.c
// Author: yazarouz
// Date: November 23, 2025
// Purpose: Demonstrate the three main loop types in C for beginners
//
// This program shows practical examples of:
// 1. for loop    → when you know how many times to repeat
// 2. while loop  → when repetition depends on a condition
// 3. do-while loop → when you must run the code at least once
//

#include <stdio.h>

int main() {
    printf("=== C Loops Demonstration ===\n\n");

    // 1. for loop: count from 1 to 5
    printf("1. for loop (count 1 to 5):\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 2. while loop: print powers of 2 up to 32
    printf("2. while loop (powers of 2 up to 32):\n");
    int value = 1;
    while (value <= 32) {
        printf("%d ", value);
        value *= 2;  // double the value each time
    }
    printf("\n\n");

    // 3. do-while loop: get valid input (1–10) from user
    printf("3. do-while loop (input validation: enter number 1–10):\n");
    int number;
    do {
        printf("Your number: ");
        scanf("%d", &number);
    } while (number < 1 || number > 10);
    printf("Valid input received: %d\n", number);

    return 0;
}