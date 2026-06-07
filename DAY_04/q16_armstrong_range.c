/*
* LOGIC: The Digit Extraction Engine
 * 1. Use modulo (n % 10) to "chop off" the last digit.
 * 2. Perform math on that digit (add, cube, factorial, etc.).
 * 3. Use division (n / 10) to permanently remove the last digit.
 * 4. Repeat in a while(n > 0) loop until the number is destroyed.
 * PRO-TIP: Always make a copy of 'n' first if you need to compare the result later!
 */

#include <stdio.h>
int main() {
    int st,end,r,originalNum,temp,count;
    scanf("%d %d",&st,&end);
    for (int j=st;j<=end;j++) {
        int result=0;
        originalNum=j;
        temp=j;
        int temp1=j;
        for (count=0;temp1!=0;count++) {
            temp1=temp1/10;
        }
        while (originalNum!=0) {
            r=originalNum%10;
            originalNum=originalNum/10;
            int cube=1;
            for (int i=0;i<count;i++) {
                cube=cube*r;
            }
            result=cube+result;
        }
        if (result==temp) {
            printf("%d ",temp);
        }
    }
    return 0;
}