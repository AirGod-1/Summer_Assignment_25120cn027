
#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int rollNo;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float average;
};

struct Student students[MAX];
int count = 0;
int next_roll_no = 1;

void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void calculateResult(struct Student *s) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += s->marks[i];
    }
    s->total = sum;
    s->average = (float)sum / SUBJECTS;
}

void addStudent() {
    if (count >= MAX) {
        printf("Student list full!\n");
        return;
    }

    struct Student s;
    s.rollNo = next_roll_no++;

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        while (scanf("%d", &s.marks[i]) != 1) {
            printf("Invalid evaluation format. Please input an integer: ");
            flushBuffer();
        }
    }
    flushBuffer();

    calculateResult(&s);
    students[count++] = s;
    printf("Student added successfully with Roll No %d\n", s.rollNo);
}

void displayStudents() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-8s %-20s %-8s %-10s\n", "Roll", "Name", "Total", "Average");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-8d %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].total,
               students[i].average);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll No to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid record lookup number.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\n--- Performance Record Found ---\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       ");
            for (int j = 0; j < SUBJECTS; j++) {
                printf("[%d] ", students[i].marks[j]);
            }
            printf("\nTotal:       %d\nAverage:     %.2f%%\n", students[i].total, students[i].average);
            return;
        }
    }
    printf("Roll No %d not found in active listings.\n", roll);
}

int main() {
    int choice;
    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection choice. Use standard menu digits.\n");
            flushBuffer();
            continue;
        }
        flushBuffer();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 0: printf("Exiting Records Engine...\n"); break;
            default: printf("Invalid choice selected. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}