#include <stdio.h>
long long fact(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
        return result;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));
    return 0;
}