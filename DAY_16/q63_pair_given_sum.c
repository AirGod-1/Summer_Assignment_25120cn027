/*
* LOGIC: The Pair Target Engine
 * 1. Use nested loops to check every possible combination of two numbers.
 * 2. If arr[i] + arr[j] == target, you found a pair.
 */

#include <stdio.h>
int main() {
    int n, target, found = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) printf("No pairs found.\n");


    return 0;
}