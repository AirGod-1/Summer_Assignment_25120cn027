/*
* LOGIC: Min/Max Engine
 * 1. Assume the first element (arr[0]) is both the largest and smallest.
 * 2. Loop from index 1 to n-1.
 * 3. Update max if arr[i] > max. Update min if arr[i] < min.
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {

        if (arr[i] > max) max = arr[i];

        if (arr[i] < min) min = arr[i];}

    printf("Largest: %d\nSmallest: %d\n", max, min);


    return 0;
}