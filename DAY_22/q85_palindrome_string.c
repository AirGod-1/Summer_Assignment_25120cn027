/*
* LOGIC: Two-Pointer Verification
 * 1. Set pointers at the start and end of the string.
 * 2. If str[start] != str[end] at any point, it's not a palindrome.
 */


#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int is_palin = 1;

    scanf("%s", str);

    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            is_palin = 0;
            break; }
        start++;
        end--;
    }
    if (is_palin) printf("Palindrome\n");
    else printf("Not a Palindrome\n");


    return 0;
}