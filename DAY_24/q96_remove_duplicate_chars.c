/*
* LOGIC: The Unique Hash Mask
 * 1. Use the hash array to track if a character has been seen.
 * 2. If hash[char] is 0, it's new. Write it, then flip hash to 1.
 * 3. If hash[char] is 1, skip it.
 */


#include <stdio.h>
int main() {
    char str[100];
    int seen[256] = {0};
    int write_idx = 0;

    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (seen[(unsigned char)str[i]] == 0) {

            str[write_idx] = str[i];
            seen[(unsigned char)str[i]] = 1; // Mark as seen
            write_idx++;
        }
    }
    str[write_idx] = '\0';
    printf("Without duplicates: %s\n", str);



    return 0;
}