/*
* LOGIC: The Divisor Engine
 * 1. Run a for-loop up to half the number (n / 2) to save processing time.
 * 2. Use modulo (n % i == 0) to check if 'i' divides perfectly without a remainder.
 * 3. If true, flip a flag (for primes) or add it to a sum (for perfect numbers).
 */

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