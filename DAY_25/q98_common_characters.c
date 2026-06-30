/*
* LOGIC: Dual Hash Intersection
 * 1. Build a hash map for String 1.
 * 2. Build a hash map for String 2.
 * 3. If BOTH hash maps have a value > 0 for a specific bucket, it's a common char.
 */



#include <stdio.h>
int main() {
    char s1[100], s2[100];
    int hash1[256] = {0}, hash2[256] = {0};

    scanf("%s %s", s1, s2);

    for (int i = 0; s1[i] != '\0'; i++) hash1[(unsigned char)s1[i]]++;
    for (int i = 0; s2[i] != '\0'; i++) hash2[(unsigned char)s2[i]]++;

    printf("Common characters: ");
    for (int i = 0; i < 256; i++) {
        if (hash1[i] > 0 && hash2[i] > 0) {
            printf("%c ", i);
        }
    }

    printf("\n");




    return 0;

}