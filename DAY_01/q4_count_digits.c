#include <stdio.h>

int main() {
    long long n;
    int count = 0;
    //Take User input
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
    //Prints the result
    printf("Number of digits = %d\n", count);

    return 0;
}