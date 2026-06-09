/*
* LOGIC: The Nested Pattern Engine
 * 1. Outer Loop (i): Controls the ROWS (Height).
 * 2. Inner Loop (j): Controls the COLUMNS (Width).
 * 3. Triangle Rule: To make the rows get wider as they go down, set the inner loop to stop at 'i' (j <= i).
 * 4. Always remember to print a newline (\n) OUTSIDE the inner loop, but INSIDE the outer loop!
 */

#include <stdio.h>
int main() {

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}