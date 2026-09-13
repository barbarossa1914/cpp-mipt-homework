#include <stdio.h>

float pi(int n){
    float sum = 0;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += (float)sign / (float)(2 * i - 1);
        sign *= -1;
    }
    return sum * 4;
}

int main(){
    printf("%f\n", pi(10));
    printf("%f\n", pi(100));
}