/*
* LOGIC: The Recursion Engine (A function that calls itself)
 * 1. The Base Case: This is the emergency brake! Always write an 'if' statement to stop the recursion (e.g., if n == 0, return 1).
 * 2. The Recursive Call: The function calls itself but with a SMALLER piece of the problem (e.g., n - 1).
 * 3. The Return: Combine the current step's math with the result of the recursive call.
 */

#include <stdio.h>

int recursive_reverse(int n,int rev) {
 if(n==0) return rev;

 rev = (rev*10)+(n%10);

 return recursive_reverse(n/10,rev);
}

int main() {
 int n,rev=0;
 scanf("%d",&n);
 printf("%d",recursive_reverse(n,rev));

}