/*
* LOGIC: Frequency Counter
 * 1. Loop through the array and compare each element to the 'target'.
 * 2. Every time arr[i] == target, increment a counter.
 */
#include <stdio.h>

int main() {
    int n, target, count = 0;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to count: ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++) {

        if (arr[i] == target) count++;
    }

    printf("Frequency: %d\n", count);


    return 0;
}