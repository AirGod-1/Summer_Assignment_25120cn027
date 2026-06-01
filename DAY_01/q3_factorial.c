#include <stdio.h>
int main() {
    int n,fact=1;
    // Ask the user for input
    
    printf("Enter a number: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {

        if(n==0||n==1) {
            return 0;
        }

        fact=fact*i;

    }
    printf("The factorial of %d is %d.", n, fact);
    return 0;
}