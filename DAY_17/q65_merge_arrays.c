/*
* LOGIC: Array Stacking
 * 1. Create a third array with size = size1 + size2.
 * 2. Loop through Array 1 and copy it to Array 3.
 * 3. Loop through Array 2 and append it to Array 3 starting at index 'size1'.
 */

#include <stdio.h>

int main() {


    int n1, n2;
    printf("Size of arr1: "); scanf("%d", &n1);
    int arr1[n1];

    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    printf("Size of arr2: "); scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);
    int merged[n1 + n2];
    for (int i = 0; i < n1; i++) merged[i] = arr1[i];
    for (int i = 0; i < n2; i++) merged[n1 + i] = arr2[i];

    printf("Merged Array: ");
    for (int i = 0; i < n1 + n2; i++) printf("%d ", merged[i]);
    printf("\n");

    return 0;
}