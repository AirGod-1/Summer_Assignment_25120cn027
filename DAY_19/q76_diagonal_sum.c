/*
* LOGIC: Diagonal Matrix Engine (Must be Square: N x N)
 * 1. Primary Diagonal: Row and Col indexes are equal (i == j).
 * 2. Secondary Diagonal: Row and Col indexes add up to n-1 (i + j == n - 1).
 */
#include <stdio.h>

int main() {
    int n, p_sum = 0, s_sum = 0;
    scanf("%d", &n);
    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (i == j) p_sum += mat[i][j];
            if (i + j == n - 1) s_sum += mat[i][j];
        }
    }

    printf("Primary Sum: %d\nSecondary Sum: %d\n", p_sum, s_sum);
    return 0;
}