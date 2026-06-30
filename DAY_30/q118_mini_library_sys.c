
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[50];
    int quantity;
};

struct Book library[MAX];
int count = 0;
int next_id = 1;
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int findBook(int id) {
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) return i;
    }
    return -1;
}
void addBook() {
    if (count >= MAX) {
        printf("Library capacity full!\n");
        return;
    }

    struct Book b;
    b.id = next_id++;
    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    while (scanf("%d", &b.quantity) != 1 || b.quantity < 0) {
        printf("Invalid quantity input. Please enter a positive integer: ");
        flushBuffer();
    }
    flushBuffer();
    library[count++] = b;
    printf("Book added successfully with ID %d\n", b.id);
}

void displayBooks() {
    if (count == 0) {
        printf("No books available in inventory.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Qty");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-20s %-10d\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].quantity);
    }
}
void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid format entry.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    int idx = findBook(id);
    if (idx == -1) {
        printf("Error: Book record not found.\n");
        return;
    }
    if (library[idx].quantity <= 0) {
        printf("Transaction Denied: All copies of this title are currently issued out.\n");
        return;
    }

    library[idx].quantity--;
    printf("Success: Book issued. Remaining stock copies: %d\n", library[idx].quantity);
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid format entry.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    int idx = findBook(id);
    if (idx == -1) {
        printf("Error: Book record not found.\n");
        return;
    }

    library[idx].quantity++;
    printf("Success: Book returned. Total stock copies available: %d\n", library[idx].quantity);
}

void searchByAuthor() {
    char author[50];
    printf("Enter author name to search: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    int found = 0;
    printf("\n--- Author Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].author, author) != NULL) {
            printf("Found -> ID: %d | Title: %-30s | Available Qty: %d\n",
                   library[i].id,
                   library[i].title,
                   library[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("No library listings match author name '%s'.\n", author);
}

int main() {
    int choice;
    do {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Search by Author\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection choice. Use standard menu digits.\n");
            flushBuffer();
            continue;
        }
        flushBuffer();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: searchByAuthor(); break;
            case 0: printf("Exiting Inventory System...\n"); break;
            default: printf("Invalid option selected. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}