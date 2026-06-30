/*
* LOGIC: The Space Transition Engine
 * 1. We count words by counting the transitions from a space to a letter.
 * 2. If current char is a space/newline, and the NEXT char is a letter, it's a new word.
 */

#include <stdio.h>
int main() {
    char str[200];
    int words = 0, i = 0;
    fgets(str, sizeof(str), stdin);

    if (str[0] != ' ' && str[0] != '\n' && str[0] != '\0') {
        words++;
    }

    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t') &&
            (str[i+1] != ' ' && str[i+1] != '\n' && str[i+1] != '\0')) {
            words++;
            }
        i++;
    }
    printf("Total words: %d\n", words);
    return 0;
}