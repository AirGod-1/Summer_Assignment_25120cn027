#include <stdio.h>
float sum(float a,float b) {
    return a+b;
}

int main() {
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%.2f",sum(a,b));
    return 0;
}