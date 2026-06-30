/*
* LOGIC: The Cross-Product Matrix Engine (O(n^3))
 * 1. Matrix A columns MUST equal Matrix B rows.
 * 2. Requires THREE nested loops: Row(i), Col(j), and Cross-Multiplier(k).
 * 3. Initialize res[i][j] to 0, then add (a[i][k] * b[k][j]).
 */
#include <stdio.h>
int main() {

    int n;
    scanf("%d", &n);
    int a[n][n], b[n][n], res[n][n];

    for (int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &a[i][j]);
    for (int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &b[i][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            res[i][j] = 0;
            for (int k = 0; k < n; k++) {

                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Product Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", res[i][j]);
        printf("\n");
    }


    return 0;

}