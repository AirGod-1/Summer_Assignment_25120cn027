// #include <stdio.h>
//
// int main() {
//     int n1,n2,gcd=0,min=0;
//     scanf("%d %d",&n1,&n2);
//
//     if (n1<=n2) min=n1;
//
//     else min=n2;
//
//     for (int i=1;i<=min;i++) {
//         if (n1%i==0 && n2%i==0) gcd=i;
//     }
//     printf("Gcd of %d and %d is %d",n1,n2,gcd);
//
//     return 0;
// }

#include <stdio.h>

int main() {
   int a, b, r;
    scanf("%d %d", &a, &b);

    while (b!=0) {
        r = a % b;
        a = b;
        b = r;
    }
    printf("GCD is: %d\n", a);
    return 0;
}