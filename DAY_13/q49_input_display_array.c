/*
* LOGIC: The Array Traversal Engine
 * 1. Declare the array and its size: int arr[100]; int size;
 * 2. Input Loop: Use a for-loop (i = 0 to size - 1) with scanf to fill it.
 * 3. Display Loop: Use a second for-loop to print elements.
 */

#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}