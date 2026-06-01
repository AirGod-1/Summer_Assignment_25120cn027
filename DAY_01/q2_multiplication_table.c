#include <stdio.h>

int main() {
    int n;

    // Ask the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nMultiplication Table of %d:\n", n);
    printf("------------------------------\n");

    // Calculate the multiplication of first 10 n natural numbers
    for (int i = 1; i <= 10; i++) {
        // Prints the result
        printf("%d x %2d = %d\n", n, i, n * i);
    }

    return 0;
}