/*
 * Author: yazarouz
 * Date: 2026-02-15
 * Simple Login System with User Menu
 * Features: 3-attempt login, profile view, password change
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ATTEMPT 3
#define CORRECT_USERNAME "admin"

char current_password[MAX_LENGTH] = "therealadmin002";

void show_user_menu() {
    printf("\n--- User Menu ---\n");
    printf("1. View profile\n");
    printf("2. Change password\n");
    printf("3. Logout\n");
    printf("Your choice: ");
}

void view_user_profile() {
    printf("\n=== User Profile ===\n");
    printf("Username: %s\n", CORRECT_USERNAME);
    printf("Status: Active\n");
    printf("Role: Administrator\n");
}

void change_user_password() {
    char new_pass[MAX_LENGTH];
    char confirm_pass[MAX_LENGTH];

    printf("\nEnter new password: ");
    fgets(new_pass, MAX_LENGTH, stdin);
    new_pass[strcspn(new_pass, "\n")] = '\0';

    printf("Confirm new password: ");
    fgets(confirm_pass, MAX_LENGTH, stdin);
    confirm_pass[strcspn(confirm_pass, "\n")] = '\0';

    if (strcmp(new_pass, confirm_pass) == 0) {
        strcpy(current_password, new_pass);
        printf("Password changed successfully!\n");
    } else {
        printf("Passwords don't match!\n");
    }
}

int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int login_flag = 0;

    printf("===========================\n");
    printf("--- Simple Login System ---\n");
    printf("===========================\n\n");

    for (int attempt = 1; attempt <= MAX_ATTEMPT; attempt++) {
        printf("\n--- Attempt %d/%d ---\n", attempt, MAX_ATTEMPT);

        printf("Username: ");
        fgets(username, MAX_LENGTH, stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password: ");
        fgets(password, MAX_LENGTH, stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strcmp(username, CORRECT_USERNAME) == 0 &&
            strcmp(password, current_password) == 0) {
            printf("\nLogin successful! Welcome %s\n", username);
            login_flag = 1;
            break;
        } else {
            printf("Invalid username or password!\n");
            if (attempt < MAX_ATTEMPT) {
                printf("Please try again...\n");
            }
        }
    }

    if (login_flag) {
        int choice;
        do {
            show_user_menu();
            scanf("%d", &choice);
            getchar();

            switch (choice) {
                case 1:
                    view_user_profile();
                    break;
                case 2:
                    change_user_password();
                    break;
                case 3:
                    printf("Logging out... Goodbye!\n");
                    break;
                default:
                    printf("Invalid option! Please choose 1-3.\n");
            }
        } while (choice != 3);
    } else {
        printf("\nAccount locked! Too many failed attempts.\n");
        printf("Please try again later.\n");
    }

    printf("\n===========================\n");
    printf("--- Thank you for using our system! ---\n");
    printf("===========================\n");

    return 0;
}