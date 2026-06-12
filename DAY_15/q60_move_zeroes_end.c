/*
* LOGIC: Zero Shifter
 * 1. Maintain a 'nonZeroIndex' starting at 0.
 * 2. Loop through the array. If arr[i] != 0, assign it to arr[nonZeroIndex] and increment the index.
 * 3. Once the loop finishes, fill the remaining slots from 'nonZeroIndex' to 'n-1' with 0s.
 */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int nonZeroIndex = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }
    for (int i = nonZeroIndex; i < n; i++) {
        arr[i] = 0;
    }
    printf("Zeroes moved to end: ");

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");


    return 0;
}