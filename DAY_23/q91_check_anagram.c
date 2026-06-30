/*
* LOGIC: The Balance Scale Engine
 * 1. If lengths are different, they aren't anagrams.
 * 2. Loop through both strings simultaneously.
 * 3. Increment the hash for string A, and DECREMENT the hash for string B.
 * 4. If they are anagrams, every single bucket in the hash will balance back to 0.
 */
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int hash[256] = {0};
    int is_anagram = 1;

    scanf("%s %s", str1, str2);
    if (strlen(str1) != strlen(str2)) {
        printf("Not Anagrams\n");
        return 0;
    }

    for (int i = 0; str1[i] != '\0'; i++) {
        hash[(unsigned char)str1[i]]++;
        hash[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (hash[i] != 0) {
            is_anagram = 0;
            break;
        }
    }
    if (is_anagram) printf("Anagrams!\n");
    else printf("Not Anagrams\n");

    return 0;

}