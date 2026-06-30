/*
* LOGIC: The Concatenation Trick
 * 1. If str1 is "ABCD" and str2 is "CDAB", they are rotations.
 * 2. Concatenate str1 to itself: "ABCDABCD".
 * 3. If str2 is a rotation, it will always exist as a substring inside the doubled string!
 */

#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[100], temp[200];

    scanf("%s %s", str1, str2);
    if (strlen(str1) != strlen(str2)) {
        printf("Not a rotation.\n");
        return 0;
    }
    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL) {
        printf("Yes, it is a rotation!\n");
    } else {
        printf("Not a rotation.\n");
    }




    return 0;
}