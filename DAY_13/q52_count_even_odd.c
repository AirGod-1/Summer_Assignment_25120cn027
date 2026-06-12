/*
* LOGIC: Array Filtering
 * 1. Use modulo (arr[i] % 2 == 0) inside the traversal loop.
 * 2. Increment an even_count or odd_count based on the result.
 */


#include <stdio.h>

int main() {
    int n, evens = 0, odds = 0;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);

        if (arr[i] % 2 == 0) evens++;
        else odds++;
    }
    printf("Even count: %d\nOdd count: %d\n", evens, odds);


    return 0;
}