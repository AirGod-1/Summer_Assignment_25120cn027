/*
* LOGIC: Matrix Transpose Engine
 * 1. Row becomes Column, Column becomes Row.
 * 2. Assign TransposeMatrix[j][i] = OriginalMatrix[i][j].
 */
#include <stdio.h>
int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols], trans[cols][rows]; // Notice dimensions swap!

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
            trans[j][i] = mat[i][j];
        }
    }
    printf("Transposed:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}