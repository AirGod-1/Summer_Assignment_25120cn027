/*
 * LOGIC: The Struct Array Engine (Contacts)
 * 1. Define a Contact struct with Name, Phone, and Email.
 * 2. Store contacts in a struct array, growing with a 'count' variable.
 * 3. Centralize input stream clearing to prevent character loss on consecutive operations.
 */



#include <stdio.h>
#include <string.h>
#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addContact() {
    if (count >= MAX) {
        printf("Contact list full!\n");
        return;
    }

    struct Contact c;

    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    contacts[count++] = c;
    printf("Contact added successfully.\n");
}

void displayContacts() {
    if (count == 0) {
        printf("No contacts saved.\n");
        return;
    }

    printf("\n%-25s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-25s %-15s %-30s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

int findContact(const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) return i;
    }
    return -1;
}

void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int idx = findContact(name);
    if (idx == -1) {
        printf("Contact not found.\n");
    } else {
        printf("Found -> Name: %s | Phone: %s | Email: %s\n",
               contacts[idx].name, contacts[idx].phone, contacts[idx].email);
    }
}

void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int idx = findContact(name);
    if (idx == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        contacts[j] = contacts[j + 1];
    }
    count--;
    printf("Contact deleted successfully.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            flushBuffer();
            continue;
        }

        flushBuffer();

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}