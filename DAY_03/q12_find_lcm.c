#include <stdio.h>

int main() {
    int a, b, r;
    scanf("%d %d", &a, &b);
int n1 =a,n2 =b,lcm=0;
    while (b!=0) {
        r = a % b;
        a = b;
        b = r;
    }
    lcm =(n1*n2)/a;
    printf( "lcm-%d",lcm);
    return 0;
}