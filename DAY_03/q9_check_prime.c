#include <stdio.h>
int main() {
    int n,isPrime=1;
    scanf("%d",&n);
    if(n==1||n==0) {
        printf("%d is not a prime.",n);
    }
    for (int i=2;i<=n/2;i++) {
        if (n==2) {
            break;
        }
        if (n%i==0) {
            isPrime=0;
            break;
        }
    }
    if (isPrime==1) {
        printf("%d is a prime number.",n);
    }
   else
       printf("%d is not a prime number.",n);
    return 0;
}