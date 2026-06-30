/*
* LOGIC: The Binary Search Engine (O(log n))
 * 1. ARRAY MUST BE SORTED FIRST!
 * 2. Define a 'low', 'high', and 'mid' pointer.
 * 3. If target is > mid, chop off the left half (low = mid + 1).
 * 4. If target is < mid, chop off the right half (high = mid - 1).
 */

#include <stdio.h>

int main() {
    int n, target, low, high, mid, found = -1;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Search target: "); scanf("%d", &target);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            found = mid; break;
        }
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (found != -1) printf("Found at index %d\n", found);
    else printf("Not found.\n");

    return 0;


}