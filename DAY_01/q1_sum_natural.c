#include <stdio.h>

int main() {
    int n, sum = 0;

    // Ask the user for input
    printf("Enter a positive integer (N): ");
    scanf("%d", &n);

    // Calculate the sum of first N natural numbers
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Prints the result
    printf("The sum of the first %d natural numbers is: %d\n", n, sum);

    return 0;
}
