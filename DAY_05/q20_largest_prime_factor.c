#include <stdio.h>
int main() {
    int n ,max=0;
    scanf("%d", &n);
if (n==0) return 0;
    for (int i=2; i<=n; i++) {
        if (n%i==0) {
            while (n%i==0) {
                max=i;
                n/=i;
            }
        }
    }
    printf("%d",max);
    return 0;
}