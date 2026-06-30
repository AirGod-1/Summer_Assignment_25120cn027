/*
* LOGIC: The Struct Database Engine
 * 1. Define a 'struct' to bundle related variables (id, name, marks).
 * 2. Create an array of structs to hold multiple entries.
 * 3. Use a 'count' variable to track how many entries exist.
 */


#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};
int main() {
    struct Student db[100];
    int count = 0, choice;
    while(1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. View All Students\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:

                printf("Enter ID: ");
                scanf("%d", &db[count].id);
                printf("Enter Name: ");
                scanf(" %[^\n]s", db[count].name);
                printf("Enter Marks: ");
                scanf("%f", &db[count].marks);
                count++;
                printf("Student added!\n");
                break;
                
            case 2:
                printf("\nID\tName\t\tMarks\n");
                printf("--------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-15s\t%.2f\n", db[i].id, db[i].name, db[i].marks);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }




    return 0;
}