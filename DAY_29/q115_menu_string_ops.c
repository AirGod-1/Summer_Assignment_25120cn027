
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 200

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    return len;
}

void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0' && src[i] != '\n') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    int choice;
    char str1[MAX_STR], str2[MAX_STR];

    while (1) {
        printf("\n--- String Utility System ---\n");
        printf("1. Find Length\n2. Copy String\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter string: ");
                fgets(str1, MAX_STR, stdin);
                printf("Length: %d\n", stringLength(str1));
                break;
            case 2:
                printf("Enter source string: ");
                fgets(str1, MAX_STR, stdin);
                stringCopy(str2, str1);
                printf("Destination String contains: %s\n", str2);
                break;
            case 3: exit(0);
            default: printf("Invalid selection.\n");
        }
    }
    return 0;
}