/*
* LOGIC: 2D Column-Wise Summation Engine
 * 1. The outer loop is 'j' (Columns). This anchors us to one specific column at a time.
 * 2. Reset the sum to 0 at the start of every new column.
 * 3. The inner loop is 'i' (Rows). This walks DOWN the current column to accumulate the sum.
 */

#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nColumn-wise Sums:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += mat[i][j];
        }
        printf("Sum of Column %d: %d\n", j + 1, sum);
    }

    return 0;
}