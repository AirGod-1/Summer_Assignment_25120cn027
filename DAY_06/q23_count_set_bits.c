#include <stdio.h>

int main() {

    int n,count = 0,temp=0;
    scanf("%d", &n);
    temp = n;


    while (n > 0) {
        n = n & (n - 1);


        count++;
    }


    printf("Set bits in %d: %d\n", temp, count);
    return 0;
}