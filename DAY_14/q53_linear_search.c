/*
* LOGIC: Linear Search Engine
 * 1. Ask user for a 'target' value.
 * 2. Loop through the array. If arr[i] == target, save the index and break.
 * 3. If the loop finishes without finding it, print "Not found".
 */


#include <stdio.h>

int main() {
    int n, target, found = -1;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);



    printf("Enter element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {

            found = i;
            break;

        }
    }

    if (found != -1) printf("Found at index: %d\n", found);
    else printf("Element not found\n");

    return 0;
}