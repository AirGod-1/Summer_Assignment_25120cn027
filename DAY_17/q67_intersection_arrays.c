/*
* LOGIC: The Overlap Engine
 * 1. Loop through Array 1.
 * 2. For each element, search Array 2.
 * 3. If a match is found, print it and break to avoid duplicate printing.
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
    printf("Intersection/Common Elements: ");
    for (int i = 0; i < n1; i++) {

        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
    printf("\n");

    return 0;


}