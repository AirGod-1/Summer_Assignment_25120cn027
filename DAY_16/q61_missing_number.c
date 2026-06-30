/*
* LOGIC: The Mathematical Missing Number Engine
 * 1. The sum of the first N natural numbers is N * (N + 1) / 2.
 * 2. Calculate this expected total.
 * 3. Loop through the array and subtract each element from the expected total.
 * 4. Whatever number is left over is the missing number.
 */

#include <stdio.h>
int main() {
    int n, sum = 0, expected_sum;
    printf("Enter the value of N (total numbers including missing): ");
    scanf("%d", &n);
    expected_sum = (n * (n + 1)) / 2;
    int arr[n - 1];

    printf("Enter the %d numbers: ", n - 1);

        for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("The missing number is: %d\n", expected_sum - sum);


    return 0;
}