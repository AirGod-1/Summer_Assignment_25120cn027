#include <stdio.h>
int main() {
    int n,product=1,r;
    scanf("%d", &n);
    while(n!=0) {
        r = n%10;
        n=n/10;
        product=product*r;
    }
    printf("%d", product);
    return 0;
}