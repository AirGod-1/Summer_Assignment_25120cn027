#include <stdio.h>

int main() {
    int n,palin=0,r,temp;
    scanf("%d", &n);
temp=n;
    while(n!=0) {
        r= n%10;
        n=n/10;
        palin=palin*10+r;
    }
    if(palin==temp) printf("%d==%d",temp,palin);
    else printf("%d!=%d",temp,palin);
    return 0;
}