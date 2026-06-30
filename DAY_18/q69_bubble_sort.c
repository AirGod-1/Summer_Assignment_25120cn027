/*
* LOGIC: The Bubble Sort Engine (O(n^2))
 * 1. Outer loop tracks passes over the array.
 * 2. Inner loop compares adjacent elements (j and j+1).
 * 3. Swap if the left is heavier than the right, "bubbling" the largest to the end.
 */


#include <stdio.h>
int main() {
    int n;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);


    return 0;

}