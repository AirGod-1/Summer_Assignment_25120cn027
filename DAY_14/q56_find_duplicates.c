/*
* LOGIC: Nested Array Comparison
 * 1. Outer loop picks an element arr[i].
 * 2. Inner loop checks all elements AHEAD of it (arr[j] where j = i + 1).
 * 3. If arr[i] == arr[j], it's a duplicate.
 */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Duplicate elements: ");
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {

                printf("%d ", arr[i]);
                break;

            }
        }
    }

    printf("\n");


    return 0;
}