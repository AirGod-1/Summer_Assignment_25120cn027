/*
* LOGIC: The Max Frequency Engine
 * 1. Use nested loops: Outer loop selects an element. Inner loop counts its occurrences.
 * 2. Keep track of the 'max_count' and the 'most_frequent' element.
 * 3. Update both whenever a higher count is found.
 */

#include <stdio.h>
int main() {
    int n, max_count = 0, most_frequent;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        int current_count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) current_count++;
        }
        if (current_count > max_count) {
            max_count = current_count;
            most_frequent = arr[i];
        }
    }

    printf("Max frequency element: %d (appears %d times)\n", most_frequent, max_count);


    return 0;

}