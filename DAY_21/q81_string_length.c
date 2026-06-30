/*
* LOGIC: The String Traversal Engine
 * 1. Start a counter at 0.
 * 2. Loop through the array until you hit the Null Terminator ('\0').
 * 3. Increment the counter on every step.
 */

#include <stdio.h>
int main() {
    char str[100];
    int length = 0;
    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);
    while (str[length] != '\0' && str[length] != '\n')
        {
        length++;
    }
    printf("Length without strlen(): %d\n", length);

    return 0;
}