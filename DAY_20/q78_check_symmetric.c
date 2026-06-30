/*
* LOGIC: Symmetric Validator
 * 1. A matrix is symmetric if Matrix[i][j] == Matrix[j][i] across the board.
 * 2. As soon as one fails, break and mark it false.
 */
#include <stdio.h>

int main() {
    int n, is_sym = 1;
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (mat[i][j] != mat[j][i]) {
                is_sym = 0; break;
            }
        }
    }
    if (is_sym) printf("Matrix is Symmetric\n");
    else printf("Matrix is NOT Symmetric\n");

    return 0;
}