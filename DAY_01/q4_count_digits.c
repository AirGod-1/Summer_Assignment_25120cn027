#include <stdio.h>

int main() {
    long long n;
    int count = 0;

    printf("Enter a number: ");
    scanf("%lld", &n);

    // Handle 0 as a special case
    if (n == 0) {
        count = 1;
    } else {
        // Handle negative numbers
        if (n < 0) {
            n = -n;
        }

        while (n != 0) {
            n /= 10;
            count++;
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}