/*
* LOGIC: The System Menu Engine
 * 1. Wrap the program in a while(1) loop to keep the menu active.
 * 2. Ask for input, check eligibility based on rules (Age >= 18).
 * 3. Use an exit option to break the loop.
 */



#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice, age;

    while(1) {
        printf("\n--- Voting Eligibility System ---\n");
        printf("1. Check Eligibility\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your age: ");
                scanf("%d", &age);
                if (age >= 18) {
                    printf("Result: You are ELIGIBLE to vote in India.\n");
                } else {
                    printf("Result: You are NOT ELIGIBLE. You must wait %d more years.\n", 18 - age);
                }
                break;
            case 2:
                printf("Shutting down system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1 or 2.\n");
        }
    }


    return 0;

}