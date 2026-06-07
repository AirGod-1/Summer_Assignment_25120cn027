#include <stdio.h>

int countSetBitsOptimized(int n) {
    int count = 0;

    while (n > 0) {
        // Erase the rightmost set bit
        n = n & (n - 1);

        // Since we successfully erased a '1', we count it
        count++;
    }

    return count;
}

int main() {
    int number;
    scanf("%d", &number);
    printf("Set bits in %d: %d\n", number, countSetBitsOptimized(number));
    return 0;
}