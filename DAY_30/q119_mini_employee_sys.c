#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[30];
    double salary;
};


struct Employee employees[MAX];
int count = 0;
int next_id = 1;
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int findEmployee(int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) return i;
    }
    return -1;
}

void addEmployee() {
    if (count >= MAX) {
        printf("Employee list full!\n");
        return;
    }

    struct Employee e;
    e.id = next_id++;

    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter Salary: ");
    while (scanf("%lf", &e.salary) != 1 || e.salary < 0) {
        printf("Invalid salary amount. Please enter a valid currency figure: ");
        flushBuffer();
    }
    flushBuffer();

    employees[count++] = e;
    printf("Employee added successfully with ID %d\n", e.id);
}

void displayEmployees() {
    if (count == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-15s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

void updateSalary() {
    int id;
    double newSalary;

    printf("Enter Employee ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid numeric format.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    int idx = findEmployee(id);
    if (idx == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("Enter new salary: ");
    while (scanf("%lf", &newSalary) != 1 || newSalary < 0) {
        printf("Invalid salary input. Please enter a valid positive number: ");
        flushBuffer();
    }
    flushBuffer();

    employees[idx].salary = newSalary;
    printf("Salary updated successfully.\n");
}

void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid numeric format.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    int idx = findEmployee(id);
    if (idx == -1) {
        printf("Employee not found.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        employees[j] = employees[j + 1];
    }
    count--;
    printf("Employee record successfully removed.\n");
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid numeric format.\n");
        flushBuffer();
        return;
    }
    flushBuffer();

    int idx = findEmployee(id);
    if (idx == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("\n--- Employee Profile Found ---\n");
    printf("ID:         %d\nName:       %s\nDepartment: %s\nSalary:     $%.2f\n",
           employees[idx].id, employees[idx].name, employees[idx].department, employees[idx].salary);
}

void averageSalary() {
    if (count == 0) {
        printf("No active employee records found to calculate metrics.\n");
        return;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += employees[i].salary;
    }
    printf("\nPayroll Metrics Summary:\n");
    printf(" -> Total Operational Count: %d\n", count);
    printf(" -> Calculated Average Salary: %.2f\n", sum / count);
}
int main() {
    int choice;
    do {
        printf("\n--- Mini Employee Management System ---\n");
        printf("1. Add Employee\n2. Display Employees\n3. Update Salary\n");
        printf("4. Delete Employee\n5. Search Employee\n6. Average Salary\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid application choice. Enter a valid selection digit.\n");
            flushBuffer();
            continue;
        }
        flushBuffer();

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateSalary(); break;
            case 4: deleteEmployee(); break;
            case 5: searchEmployee(); break;
            case 6: averageSalary(); break;
            case 0: printf("Exiting Payroll System...\n"); break;
            default: printf("Invalid choice option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}