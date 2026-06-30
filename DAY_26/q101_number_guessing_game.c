/*
* LOGIC: The Game Loop Engine
 * 1. Use srand() and rand() to generate a random target number.
 * 2. Use a while loop to keep asking the user for a guess until they match the target.
 * 3. Provide "Higher" or "Lower" hints.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int target, guess, attempts = 0;
    srand(time(0));
    target = rand() % 100 + 1; // Random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > target) {
            printf("Too high! Try again.\n");
        } else if (guess < target) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You found it in %d attempts!\n", attempts);
        }
    } while (guess != target);

    return 0;
}