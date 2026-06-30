/*
* LOGIC: The Zipper Engine (Two-Pointer Merge)
 * 1. Use pointers i and j to track the fronts of Array A and Array B.
 * 2. Compare A[i] and B[j]. Drop the smaller one into Array C and increment.
 * 3. Once one array empties, dump the rest of the other array into C.
 */



#include <stdio.h>
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = 4, n2 = 4, n3 = n1 + n2;
    int arr3[8];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1) arr3[k++] = arr1[i++];
    while (j < n2) arr3[k++] = arr2[j++];

    printf("Merged sorted array: ");
    for (int x = 0; x < n3; x++) printf("%d ", arr3[x]);
    printf("\n");



    return 0;
}