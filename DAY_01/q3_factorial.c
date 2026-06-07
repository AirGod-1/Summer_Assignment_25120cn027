#include <stdio.h>
int main() {
    int n,fact=1;
    // Ask the user for input
    
    printf("Enter a number: ");
    scanf("%d",&n);
    // calculates the factorial using for loop
    for(int i=1;i<=n;i++) {

        if(n==0||n==1) {
            return 0;
        }

        fact=fact*i;

    }
    //prints the factorial
    printf("The factorial of %d is %d.", n, fact);
    return 0;
}