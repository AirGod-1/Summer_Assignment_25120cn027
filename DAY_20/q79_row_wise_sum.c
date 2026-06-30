/*
* LOGIC: 2D Summation Engine
 * 1. For row-wise, the outer loop is 'i' (Rows).
 * 2. Reset sum to 0 at the start of every row.
 * 3. Loop through 'j' (Cols) to accumulate the sum.
 */
#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) scanf("%d", &mat[i][j]);

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
        printf("Sum of Row %d: %d\n", i + 1, sum);
    }
    return 0;
}