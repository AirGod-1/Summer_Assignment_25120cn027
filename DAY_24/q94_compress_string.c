/*
* LOGIC: Consecutive Counter
 * 1. Loop through the string.
 * 2. While the next character is the same, increment a counter.
 * 3. Print the character and the counter (e.g., a3), then skip forward.
 */
#include <stdio.h>
int main() {
    char str[100];
    scanf("%s", str);
    printf("Compressed: ");
    for (int i = 0; str[i] != '\0'; i++) {
        int count = 1;
        while (str[i] == str[i+1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");



    return 0;

}