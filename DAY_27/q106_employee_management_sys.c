/*
* LOGIC: Employee Struct System
 * Identical structure to the Student Record System, but with employee fields.
 */


#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char name[50];
    float salary;
};

int main() {

    struct Employee emp[100];
    int count = 0, choice;

    while(1) {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n2. View Employees\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp[count].empId);
                printf("Enter Name: ");
                scanf(" %[^\n]s", emp[count].name);
                printf("Enter Salary: Rs. ");
                scanf("%f", &emp[count].salary);
                count++;
                printf("Employee added successfully.\n");

                break;

            case 2:
                printf("\nEMP ID\tName\t\tSalary\n");
                printf("--------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-15s\tRs. %.2f\n", emp[i].empId, emp[i].name, emp[i].salary);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }


    return 0;
}