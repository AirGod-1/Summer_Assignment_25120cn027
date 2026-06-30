/*
* LOGIC: The Selection Sort Engine (O(n^2))
 * 1. Find the absolute minimum element in the unsorted portion.
 * 2. Swap it directly with the first unsorted position (i).
 * 3. Faster than Bubble Sort because it only swaps once per pass.
 */

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;
        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;


}