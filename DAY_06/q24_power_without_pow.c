#include <stdio.h>

int main() {
    int x,n;
    printf("Base and power : ");
    scanf("%d %d", &x,&n);
    int n1=n;
    long long result = 1;
    long long base = x;

    while (n > 0) {
        if (n % 2 != 0) {
            result = result * base;
        }
        base = base * base;
        n = n / 2;
    }

    printf("%d ^ %d = %lld\n", x, n1, result);
    return 0;
}