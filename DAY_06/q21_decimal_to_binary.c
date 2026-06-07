#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);
    long long binary=0,placeholder=1;

    while(n>0) {
        int bit = n%2;
        binary=binary+placeholder*bit;
        n=n/2;
        placeholder=placeholder*10;
    }
    printf("%lld",binary);

    return 0;
}