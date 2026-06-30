/*
* LOGIC: The In-Place Overwrite Engine
 * 1. Keep a separate 'write_index' starting at 0.
 * 2. Loop through the string. If the char is NOT a space, write it to str[write_index] and advance the index.
 * 3. Cap the end with '\0'.
 */

#include <stdio.h>
int main() {
    char str[100];
    int write_index = 0;
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] != ' ') {
            str[write_index] = str[i];
            write_index++;
        }
    }
    str[write_index] = '\0';
    printf("Without spaces: %s\n", str);


    return 0;
}