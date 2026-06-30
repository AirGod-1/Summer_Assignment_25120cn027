/*
* LOGIC: In-Place Unique Array Engine
 * 1. Create a new tracker for 'unique' elements.
 * 2. Loop through the original array. For each element, check if it already exists in the unique section.
 * 3. If it doesn't, add it to the unique section.
 */
#include <stdio.h>
int main() {
    int n, unique_count = 0;
    scanf("%d", &n);
    int arr[n], unique_arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {

        int is_duplicate = 0;

        for (int j = 0; j < unique_count; j++) {
            if (arr[i] == unique_arr[j]) {
                is_duplicate = 1;
                break;
            }

        }
        if (!is_duplicate) {

            unique_arr[unique_count] = arr[i];
            unique_count++;
        }
    }

    printf("Array without duplicates: ");
    for (int i = 0; i < unique_count; i++) printf("%d ", unique_arr[i]);
    printf("\n");

    return 0;
}