/*
* LOGIC: The ASCII Hash Map (O(n))
 * 1. Create an integer array of size 256 (all possible ASCII characters), initialized to 0.
 * 2. As you read the string, use the character itself as the index (e.g., hash['A']++).
 */

#include <stdio.h>
int main() {
    char str[100];
    int freq[256] = {0};
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d times\n", i, freq[i]);
        }
    }
    return 0;
}