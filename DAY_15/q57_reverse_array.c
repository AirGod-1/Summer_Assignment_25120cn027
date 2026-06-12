/*
* LOGIC: Two-Pointer Swap
 * 1. Set a 'start' index to 0 and an 'end' index to n-1.
 * 2. While start < end, swap arr[start] with arr[end].
 * 3. Increment start, decrement end.
 */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int start = 0, end = n - 1;
    while (start < end) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");


    return 0;
}