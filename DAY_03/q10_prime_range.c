#include <stdio.h>
int main() {
    int start,end;
    scanf("%d %d",&start,&end);

    for(int i=start;i<=end;i++) {
        if (i<=1) {
            continue;
        }

        int isprime=1;

        for(int j=2;j<=i/2;j++) {

            if(i%j==0) {
                isprime=0;
                    break;

            }

        }
        if(isprime==1) {
            printf("%d\n",i);
        }


    }
    return 0;
}