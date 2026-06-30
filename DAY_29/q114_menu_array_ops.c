
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insertElement(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteByIndex(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted.\n");
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array State: [ ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}

int main() {
    int arr[MAX_SIZE], size = 0, choice, val, idx;

    while (1) {
        printf("\n--- Array Operations System ---\n");
        printf("1. Insert\n2. Delete by Index\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val);
                insertElement(arr, &size, val);
                break;
            case 2:
                printf("Enter index (0 to %d): ", size > 0 ? size - 1 : 0);
                scanf("%d", &idx);
                deleteByIndex(arr, &size, idx);
                break;
            case 3: displayArray(arr, size); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}