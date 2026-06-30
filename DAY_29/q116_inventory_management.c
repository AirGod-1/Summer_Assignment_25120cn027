
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int stock;
} Product;

void addProduct(Product inv[], int *count) {
    if (*count >= MAX_ITEMS) return;
    printf("Enter ID: "); scanf("%d", &inv[*count].id);
    printf("Enter Name: "); scanf(" %[^\n]s", inv[*count].name);
    printf("Enter Stock: "); scanf("%d", &inv[*count].stock);
    (*count)++;
    printf("Product registered.\n");
}

void displayInventory(Product inv[], int count) {
    printf("\nID\tName\t\tStock\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%d\n", inv[i].id, inv[i].name, inv[i].stock);
    }
}

int main() {
    Product inventory[MAX_ITEMS];
    int count = 0, choice;

    while (1) {
        printf("\n--- Inventory Management ---\n");
        printf("1. Add Product\n2. View Stock\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(inventory, &count); break;
            case 2: displayInventory(inventory, count); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}