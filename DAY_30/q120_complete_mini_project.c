#include <stdio.h>
#include <string.h>

#define MAX 50

struct Book {
    int id;
    char title[100];
    int quantity;
};

struct Student {
    int rollNo;
    char name[50];
    int issuedBookId;
};

struct Book books[MAX];
int bookCount = 0;

struct Student students[MAX];
int studentCount = 0;


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



int findBookIndex(int id) {
    for (int i = 0; i < bookCount; i++)
        if (books[i].id == id) return i;
    return -1;
}

void addBook() {
    if (bookCount >= MAX) { printf("Book list full!\n"); return; }
    struct Book b;
    b.id = bookCount + 1;
    
    printf("Enter Book Title: ");
    clearBuffer(); // Clear buffer before fgets
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    
    printf("Enter Quantity: ");
    while (scanf("%d", &b.quantity) != 1) {
        printf("Invalid input. Please enter a number for quantity: ");
        clearBuffer();
    }
    
    books[bookCount++] = b;
    printf("Book added successfully with ID %d\n", b.id);
}

void displayBooks() {
    if (bookCount == 0) { printf("No books available.\n"); return; }
    printf("\n%-5s %-30s %-10s\n", "ID", "Title", "Qty");
    printf("------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++)
        printf("%-5d %-30s %-10d\n", books[i].id, books[i].title, books[i].quantity);
}


int findStudentIndex(int roll) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].rollNo == roll) return i;
    return -1;
}

void addStudent() {
    if (studentCount >= MAX) { printf("Student list full!\n"); return; }
    struct Student s;
    s.rollNo = studentCount + 1;
    
    printf("Enter Student Name: ");
    clearBuffer(); // Clear buffer before fgets
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    s.issuedBookId = 0;
    
    students[studentCount++] = s;
    printf("Student added successfully with Roll No %d\n", s.rollNo);
}

void displayStudents() {
    if (studentCount == 0) { printf("No students registered.\n"); return; }
    printf("\n%-6s %-20s %-20s\n", "Roll", "Name", "Issued Book");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        char bookInfo[100] = "None";
        if (students[i].issuedBookId != 0) {
            int bIdx = findBookIndex(students[i].issuedBookId);
            if (bIdx != -1) strcpy(bookInfo, books[bIdx].title);
        }
        printf("%-6d %-20s %-20s\n", students[i].rollNo, students[i].name, bookInfo);
    }
}



void issueBookToStudent() {
    int roll, bookId;
    
    printf("Enter Student Roll No: ");
    if (scanf("%d", &roll) != 1) { printf("Invalid input.\n"); return; }
    
    int sIdx = findStudentIndex(roll);
    if (sIdx == -1) { printf("Student not found.\n"); return; }
    if (students[sIdx].issuedBookId != 0) { printf("Student already has a book issued.\n"); return; }

    printf("Enter Book ID to issue: ");
    if (scanf("%d", &bookId) != 1) { printf("Invalid input.\n"); return; }
    
    int bIdx = findBookIndex(bookId);
    if (bIdx == -1) { printf("Book not found.\n"); return; }
    if (books[bIdx].quantity <= 0) { printf("No copies available right now.\n"); return; }

    books[bIdx].quantity--;
    students[sIdx].issuedBookId = bookId;
    printf("Success! Book \"%s\" issued to %s.\n", books[bIdx].title, students[sIdx].name);
}

void returnBookFromStudent() {
    int roll;
    printf("Enter Student Roll No: ");
    if (scanf("%d", &roll) != 1) { printf("Invalid input.\n"); return; }
    
    int sIdx = findStudentIndex(roll);
    if (sIdx == -1) { printf("Student not found.\n"); return; }
    if (students[sIdx].issuedBookId == 0) { printf("This student has no book currently issued.\n"); return; }

    int bIdx = findBookIndex(students[sIdx].issuedBookId);
    if (bIdx != -1) books[bIdx].quantity++;
    students[sIdx].issuedBookId = 0;
    
    printf("Book returned successfully.\n");
}



void searchStudentByName() {
    char name[50];
    printf("Enter name (or part of it) to search: ");
    clearBuffer();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < studentCount; i++) {

        if (strstr(students[i].name, name) != NULL) {
            printf("Found -> Roll: %d | Name: %s\n", students[i].rollNo, students[i].name);
            found = 1;
        }
    }
    if (!found) printf("No matching student found.\n");
}



int main() {
    int choice;
    do {
        printf("\n--- Student-Library Portal (Complete Mini Project) ---\n");
        printf("1. Add Book\n2. Display Books\n3. Add Student\n4. Display Students\n");
        printf("5. Issue Book to Student\n6. Return Book from Student\n7. Search Student by Name\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearBuffer();
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: addStudent(); break;
            case 4: displayStudents(); break;
            case 5: issueBookToStudent(); break;
            case 6: returnBookFromStudent(); break;
            case 7: searchStudentByName(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}