/*
* LOGIC: The Hash Max Finder
 * 1. Populate the 256-bucket hash array.
 * 2. Loop through the hash array to find the bucket with the highest value.
 */
#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int max_count = 0;
    char max_char;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > max_count) {
            max_count = freq[i];
            max_char = i;
        }
    }

    printf("Max character: '%c' (%d times)\n", max_char, max_count);
    return 0;
}