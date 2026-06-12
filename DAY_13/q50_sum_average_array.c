/*
* LOGIC: Array Accumulator
 * 1. Initialize an integer sum to 0.
 * 2. Loop through the array and add each arr[i] to sum.
 * 3. Calculate average as a float: (float)sum / size.
 */

#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    float avg = (float)sum / n;
    printf("Sum: %d\nAverage: %.2f\n", sum, avg);
    return 0;
}