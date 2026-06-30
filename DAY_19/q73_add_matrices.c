/*
* LOGIC: Matrix Addition Engine
 * 1. Use nested loops (Rows = i, Columns = j).
 * 2. Result Matrix [i][j] = Mat A [i][j] + Mat B [i][j].
 */
#include <stdio.h>
int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int a[rows][cols], b[rows][cols], res[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) scanf("%d", &a[i][j]);

    for (int i = 0; i < rows; i++)

        for (int j = 0; j < cols; j++) {
            scanf("%d", &b[i][j]);
            res[i][j] = a[i][j] + b[i][j];
        }
    printf("Result Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;

}