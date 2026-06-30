/*
* LOGIC: Word Boundary Tracker
 * 1. Walk through the string keeping track of current word length.
 * 2. On hitting a space, compare current length against max length.
 * 3. If larger, update max length and save the start index.
 */

#include <stdio.h>
#include <string.h>
int main() {
    char str[200];
    int max_len = 0, curr_len = 0, max_start = 0, curr_start = 0;

    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
            if (curr_len > max_len) {
                max_len = curr_len;
                max_start = curr_start;
            }
            curr_len = 0;
            curr_start = i + 1;
        } else {
            curr_len++;
        }
    }
    printf("Longest word: ");
    for (int i = 0; i < max_len; i++) {
        printf("%c", str[max_start + i]);
    }
    printf("\n");

    return 0;
}