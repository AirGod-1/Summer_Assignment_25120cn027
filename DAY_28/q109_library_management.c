/*
 * LOGIC: The Library State Engine
 * 1. Define a struct for Books (ID, Title, and an 'isIssued' flag).
 * 2. When a book is issued, change the flag from 0 to 1 so it cannot be issued twice.
 * 3. Use an independent 'next_id' tracker to prevent ID collisions upon deletion.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for strcspn and strstr

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[50];
    int issued; // 0 = available, 1 = issued
};

// Global State
struct Book library[MAX];
int count = 0;
int next_id = 1; // Tracks the next available ID safely

void addBook() {
    if (count >= MAX) {
        printf("Library full!\n");
        return;
    }

    struct Book b;
    b.id = next_id++; // Use and increment the global ID tracker

    printf("Enter Title: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // Strip the newline character

    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    b.issued = 0;
    library[count++] = b;

    printf("Book added successfully with ID %d\n", b.id);
}

void displayBooks() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-20s %-10s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    char key[100];
    printf("Enter title (or part of it) to search: ");
    getchar();
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, key) != NULL) {
            printf("Found -> ID: %d | Title: %s | Author: %s | Status: %s\n",
                   library[i].id,
                   library[i].title,
                   library[i].author,
                   library[i].issued ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) printf("No books matching '%s' were found.\n", key);
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].issued) {
                printf("Error: Book is already issued.\n");
            } else {
                library[i].issued = 1;
                printf("Success: Book issued.\n");
            }
            return;
        }
    }
    printf("Error: Book ID not found.\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (!library[i].issued) {
                printf("Notice: Book was not currently issued.\n");
            } else {
                library[i].issued = 0;
                printf("Success: Book returned.\n");
            }
            return;
        }
    }
    printf("Error: Book ID not found.\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            // Shift all subsequent books one position to the left
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Success: Book deleted.\n");
            return;
        }
    }
    printf("Error: Book ID not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        // Basic check to prevent infinite loops if a letter is entered
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear the bad input
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 0: printf("Exiting System...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}