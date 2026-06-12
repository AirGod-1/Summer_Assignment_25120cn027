/*
* LOGIC: Left Shift Engine
 * 1. Save the first element: int first = arr[0];
 * 2. Loop from 0 to n-2, pulling the next element backwards: arr[i] = arr[i+1];
 * 3. Place the saved 'first' element at the very end: arr[n-1] = first;
 */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n > 0) {

        int first = arr[0];
        for (int i = 0; i < n - 1; i++) {

            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }

    printf("Left rotated: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");


    return 0;

}