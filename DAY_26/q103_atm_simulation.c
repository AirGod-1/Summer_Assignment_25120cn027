/*
* LOGIC: The State-Tracker Engine
 * 1. Maintain a 'balance' variable outside the loop.
 * 2. Deposit adds to balance. Withdraw subtracts (but must verify funds first!).
 */


#include <stdio.h>
#include <stdlib.h>
int main() {
    float balance = 130806.00;
    int choice;
    float amount;

    while(1) {
        printf("\n--- ATM Simulation ---\n");
        printf("1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: Rs. ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter withdrawal amount: Rs. ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds!\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 4:
                printf("Thank you for using our ATM.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}