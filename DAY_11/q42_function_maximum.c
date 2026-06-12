#include <stdio.h>
float max(float a,float b) {
    return a>=b?a:b;
}

int main() {
    float a,b;
    scanf("%f %f",&a,&b);
    printf("max is %.2f",max(a,b));
    return 0;
}