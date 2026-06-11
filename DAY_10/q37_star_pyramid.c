/*
* LOGIC: The Centered Pyramid Engine
 * 1. Inside the outer loop (i), use TWO inner loops side-by-side.
 * 2. Loop 1 (Spaces): Runs from 1 to (n - i). This pushes the cursor to the right.
 * 3. Loop 2 (Characters): Runs from 1 to (2 * i - 1) for a standard solid pyramid.
 * 4. For palindromes (12321), split the character loop: one counting up to 'i', one counting down from 'i - 1'.
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}