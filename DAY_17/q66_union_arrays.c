/*
* LOGIC: Union Set Engine
 * 1. First, print all elements from Array 1.
 * 2. Next, loop through Array 2. Check if the element exists in Array 1.
 * 3. If it does NOT exist in Array 1, print it.
 */


#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);
    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    printf("Union: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);

    for (int i = 0; i < n2; i++) {
        int found = 0;
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                found = 1; break;
            }
        }
        if (!found) printf("%d ", arr2[i]);
    }
    printf("\n");


    return 0;

}