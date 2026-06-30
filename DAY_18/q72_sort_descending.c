/*
* LOGIC: Descending Bubble Sort
 * 1. Identical to Bubble Sort, but flip the comparison operator.
 * 2. Swap if arr[j] < arr[j+1] to bubble the SMALLEST elements to the end.
 */
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Descending Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}