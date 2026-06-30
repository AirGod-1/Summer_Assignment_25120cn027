/*
* LOGIC: The Quiz Engine
 * 1. Print questions and options manually.
 * 2. Track a 'score' variable.
 * 3. Compare user input against the hardcoded correct answer.
 */



#include <stdio.h>


int main() {



    int score = 0, answer;

    printf("--- Welcome to the C Programming Quiz ---\n\n");

    printf("Q1: Who is the father of C language?\n");
    printf("1. Steve Jobs\n2. James Gosling\n3. Dennis Ritchie\n4. Rasmus Lerdorf\n");
    printf("Answer: ");
    scanf("%d", &answer);

    if (answer == 3) { printf("Correct!\n"); score += 10; }
    else { printf("Wrong. Correct answer is 3.\n"); }

    printf("\nQ2: All C programs must contain which function?\n");
    printf("1. start()\n2. system()\n3. main()\n4. printf()\n");
    printf("Answer: ");
    scanf("%d", &answer);
    if (answer == 3) { printf("Correct!\n"); score += 10; }
    else { printf("Wrong. Correct answer is 3.\n"); }

    printf("\n--- Final Result ---\n");
    printf("You scored %d out of 20 points.\n", score);






    return 0;



}