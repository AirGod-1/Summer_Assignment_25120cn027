/*
* LOGIC: Two-Pass Hash Map
 * 1. Pass 1: Count frequency of all characters in the hash array.
 * 2. Pass 2: Read the string from the beginning. Check the hash.
 * 3. The first character whose hash == 1 is the first non-repeating.
 */

#include <stdio.h>
int main() {
    char str[100];
    int freq[256] = {0};

    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First non-repeating: '%c'\n", str[i]);
            return 0;
        }
    }
    printf("None found.\n");
    return 0;
}