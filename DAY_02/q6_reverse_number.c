#include <stdio.h>
int main() {
    int n,temp=0,r;
    scanf("%d", &n);
    while(n!=0) {
        r=n%10;
        n=n/10;
        temp=temp*10+r;
    }
    printf("%d", temp);
    return 0;
}