#include <stdio.h>
int main() {
    int n,r,sum=0;
    scanf("%d",&n);
        int num=n;
    while(n!=0) {
        r=n%10;
        n=n/10;
        int fact=1;
        for(int i=1;i<=r;i++) {

            fact=fact*i;
        }
        sum=sum+fact;


    }
    if(sum==num) printf("YES");

    else printf("NO");

    return 0;

}