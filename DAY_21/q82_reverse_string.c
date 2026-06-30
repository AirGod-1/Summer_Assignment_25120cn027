/*
* LOGIC: The Two-Pointer String Swap
 * 1. Find the length of the string.
 * 2. Set 'start' at 0, and 'end' at length - 1.
 * 3. Swap the characters and move the pointers inward.
 */

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);


    return 0;
}