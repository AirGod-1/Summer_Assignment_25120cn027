/*
* LOGIC: ASCII Math Engine
 * 1. In ASCII, 'a' is 97 and 'A' is 65. The difference is exactly 32.
 * 2. To make a lowercase letter uppercase, simply subtract 32.
 */

#include <stdio.h>
int main() {
    char str[100];

    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    printf("Uppercase: %s\n", str);
    
    return 0;
}