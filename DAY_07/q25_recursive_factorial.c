/*
* LOGIC: The Recursion Engine (A function that calls itself)
 * 1. The Base Case: This is the emergency brake! Always write an 'if' statement to stop the recursion (e.g., if n == 0, return 1).
 * 2. The Recursive Call: The function calls itself but with a SMALLER piece of the problem (e.g., n - 1).
 * 3. The Return: Combine the current step's math with the result of the recursive call.
 */

#include <stdio.h>

int factorial(int n) {

    if (n == 0||n==1) {
        return 1;
    }
        return n*factorial(n-1);
    }
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", factorial(n));
}