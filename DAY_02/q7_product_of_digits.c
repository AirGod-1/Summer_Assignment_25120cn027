/*
* LOGIC: The Digit Extraction Engine
 * 1. Use modulo (n % 10) to "chop off" the last digit.
 * 2. Perform math on that digit (add, cube, factorial, etc.).
 * 3. Use division (n / 10) to permanently remove the last digit.
 * 4. Repeat in a while(n > 0) loop until the number is destroyed.
 * PRO-TIP: Always make a copy of 'n' first if you need to compare the result later!
 */

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