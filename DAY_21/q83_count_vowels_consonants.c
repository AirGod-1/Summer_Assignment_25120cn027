/*
* LOGIC: The Character Filter
 * 1. Loop until '\0'.
 * 2. Check if the character is an alphabet letter.
 * 3. Check if it equals a, e, i, o, u (both cases). Increment vowel count.
 * 4. Otherwise, it must be a consonant.
 */


#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}