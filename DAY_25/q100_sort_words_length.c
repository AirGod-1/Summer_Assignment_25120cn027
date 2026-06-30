/*
* LOGIC: 2D String Sorting Engine
 * 1. Store names in a 2D char array (e.g., 5 strings, 50 chars each).
 * 2. Use a standard Bubble Sort.
 * 3. Instead of simple math (arr[j] > arr[j+1]), use string functions (strcmp / strlen) to compare.
 * 4. Use strcpy to execute the swap.
 */



#include <stdio.h>
#include <string.h>
int main() {
    int n;
    printf("How many names? ");
    scanf("%d", &n);

    char names[n][50];
    char temp[50];
    printf("Enter names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (strlen(names[j]) > strlen(names[j+1])) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }

    printf("\nSorted Alphabetically:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }


    return 0;


}