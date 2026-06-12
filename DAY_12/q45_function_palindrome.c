#include <stdio.h>
int palindrome(int n) {
    int r=0,temp=n,palin=0;
    while (temp!=0) {
        r=temp%10;
        temp=temp/10;
        palin=palin*10+r;
    }
    if (palin==n) {return 1;}
    else {return 0;}
}

int main() {
    int n;
    scanf("%d",&n);

    if (palindrome(n)==1) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}