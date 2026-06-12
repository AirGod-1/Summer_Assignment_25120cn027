/*
* LOGIC: Right Shift Engine
 * 1. Save the last element: int last = arr[n-1];
 * 2. Loop BACKWARDS from n-1 down to 1, pushing elements right: arr[i] = arr[i-1];
 * 3. Place the saved 'last' element at the very beginning: arr[0] = last;
 */


#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n > 0) {

        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--) {

            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }

    printf("Right rotated: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");


    return 0;
}