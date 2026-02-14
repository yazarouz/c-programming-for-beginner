/*
 * Author: yazarouz
 * Date: 2026-02-15
 * Shopping List Manager
 * Features: File persistence, capacity control, item management with quantities
 */

#include <stdio.h>
#include <string.h>
#define FILENAME "shopping_list.txt"
#define MAX_LENGTH 100

typedef struct {
    char item_name[MAX_LENGTH];
    int quantity;
} ITEM;

void add_item(ITEM list[], int *count) {
    printf("Enter item name: ");
    fgets(list[*count].item_name, MAX_LENGTH, stdin);
    list[*count].item_name[strcspn(list[*count].item_name, "\n")] = '\0';

    printf("Enter quantity for %s: ", list[*count].item_name);
    scanf("%d", &list[*count].quantity);
    getchar();

    (*count)++;
}

void save_to_file(ITEM list[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Cannot open file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", list[i].item_name, list[i].quantity);
    }

    fclose(file);
    printf("Shopping list saved to '%s'\n", FILENAME);
}

int load_from_file(ITEM list[], int max_items) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous list found. Starting fresh.\n");
        return 0;
    }

    int count = 0;
    while (count < max_items && fscanf(file, "%s %d", list[count].item_name, &list[count].quantity) == 2) {
        count++;
    }

    fclose(file);
    printf("Loaded %d items from '%s'\n", count, FILENAME);
    return count;
}

void display_list(ITEM list[], int count) {
    if (count == 0) {
        printf("Shopping list is empty!\n");
        return;
    }

    printf("\n--- Shopping List (%d items) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s (x%d)\n", i + 1, list[i].item_name, list[i].quantity);
    }
}

int main() {
    printf("=============================\n");
    printf("  Shopping List Manager\n");
    printf("=============================\n");

    int capacity;
    printf("Enter maximum capacity of list: ");
    scanf("%d", &capacity);
    getchar();

    if (capacity <= 0) {
        printf("Invalid capacity!\n");
        return 1;
    }

    ITEM shopping_list[capacity];

    int count = load_from_file(shopping_list, capacity);
    display_list(shopping_list, count);

    int new_items;
    printf("\nHow many NEW items do you want to add? ");
    scanf("%d", &new_items);
    getchar();

    if (new_items < 0) {
        printf("Invalid number!\n");
        return 1;
    }

    if (count + new_items > capacity) {
        printf("Error: List capacity exceeded! Maximum %d more items can be added.\n", capacity - count);
        new_items = capacity - count;
        printf("Adding only %d items.\n", new_items);
    }

    for (int i = 0; i < new_items; i++) {
        printf("\n--- Adding item %d/%d ---\n", i + 1, new_items);
        add_item(shopping_list, &count);
    }

    save_to_file(shopping_list, count);
    printf("\n--- Final List ---\n");
    display_list(shopping_list, count);

    printf("\nGoodbye! Your list is saved.\n");
    return 0;
}