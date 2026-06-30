/*
 * LOGIC: The Struct Array Engine (Bank)
 * 1. Define an Account struct with Account Number, Name, and Balance.
 * 2. Keep track of total accounts using a 'count' variable.
 * 3. Use an independent 'next_acc_no' variable to prevent ID collisions upon deletion.
 * 4. Validate withdrawals against the current balance before deducting.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    char name[50];
    double balance;
};

struct Account accounts[MAX];
int count = 0;
int next_acc_no = 1001;

void createAccount() {
    if (count >= MAX) {
        printf("Cannot create more accounts. Bank capacity reached.\n");
        return;
    }

    struct Account a;
    a.accNo = next_acc_no++;

    printf("Enter Account Holder Name: ");
    getchar();
    fgets(a.name, sizeof(a.name), stdin);
    a.name[strcspn(a.name, "\n")] = '\0';

    printf("Enter Initial Deposit: ");
    scanf("%lf", &a.balance);

    accounts[count++] = a;
    printf("Account created successfully. Account No: %d\n", a.accNo);
}

int findAccount(int accNo) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accNo == accNo) return i;
    }
    return -1;
}

void deposit() {
    int accNo;
    double amt;

    printf("Enter Account No: ");
    scanf("%d", &accNo);

    int idx = findAccount(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amt);
    if (amt <= 0) {
        printf("Invalid amount. Must be greater than 0.\n");
        return;
    }

    accounts[idx].balance += amt;
    printf("Deposit successful. New balance: %.2f\n", accounts[idx].balance);
}

void withdraw() {
    int accNo;
    double amt;

    printf("Enter Account No: ");
    scanf("%d", &accNo);

    int idx = findAccount(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amt);
    if (amt <= 0) {
        printf("Invalid amount. Must be greater than 0.\n");
        return;
    }
    if (amt > accounts[idx].balance) {
        printf("Transaction declined: Insufficient balance.\n");
        return;
    }

    accounts[idx].balance -= amt;
    printf("Withdrawal successful. New balance: %.2f\n", accounts[idx].balance);
}

void displayAccounts() {
    if (count == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("\n%-10s %-25s %-15s\n", "Acc No", "Name", "Balance");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-15.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
    }
}

void deleteAccount() {
    int accNo;
    printf("Enter Account No to delete: ");
    scanf("%d", &accNo);

    int idx = findAccount(accNo);
    if (idx == -1) {
        printf("Account not found.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        accounts[j] = accounts[j + 1];
    }
    count--;
    printf("Account %d successfully deleted.\n", accNo);
}

int main() {
    int choice;
    do {
        printf("\n--- Bank Account System ---\n");
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Accounts\n5. Delete Account\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid menu number.\n");
            while(getchar() != '\n'); // Flushes the bad input stream
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccounts(); break;
            case 5: deleteAccount(); break;
            case 0: printf("Exiting system...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}