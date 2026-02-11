// Author: yazarouz || Date: 2026/02/02
// Number Guessing Game - Educational C Implementation
// Purpose: Demonstrate core C concepts (randomization, loops,
//conditionals, I/O) through an interactive CLI game
// Rules: Guess a random number (1-100) within 7 attempts

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // برای srand() و time()

int game(int secret_number) {
    printf("\nThe number is between 1 and 100.\n");
    printf("You have 7 attempts to guess it!\n\n");
    
    for (int attempt = 1; attempt <= 7; attempt++) {
        int guess;
        printf("Attempt %d/7 - Guess a number: ", attempt);
        scanf("%d", &guess);
        
        if (guess == secret_number) {
            printf("Congratulations! You guessed it in %d attempts!\n", attempt);
            return 1;
        } 
        else if (guess < secret_number) {
            printf("🔼 Too low!\n");
        } 
        else {
            printf("🔽 Too high!\n");
        }
        
        if (attempt == 7) {
            printf(" Game over! The number was %d.\n", secret_number);
        } else {
            printf("You have %d attempts left.\n\n", 7 - attempt);
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    
    int random_number = rand() % 100 + 1;
    
    printf("=========================\n");
    printf("--- Guess Number Game ---\n");
    printf("=========================\n\n");
    
    game(random_number);
    
    return 0;
}