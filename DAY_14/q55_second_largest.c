/*
* LOGIC: Two-Pointer Tracker
 * 1. Maintain two variables: largest and second_largest.
 * 2. If arr[i] > largest, second_largest becomes largest, and largest becomes arr[i].
 * 3. Else if arr[i] > second_largest (and isn't equal to largest), update second_largest.
 */


#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int max = INT_MIN, second_max = INT_MIN;
    for (int i = 0; i < n; i++) {

        if (arr[i] > max)
            {
            second_max = max;
            max = arr[i];

        }
        else if (arr[i] > second_max && arr[i] != max)
            {
            second_max = arr[i];
        }
    }

    if (second_max == INT_MIN) printf("No second largest element.\n");
    else printf("Second largest: %d\n", second_max);


    return 0;
}