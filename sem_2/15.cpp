#include <stdio.h>

float yearfrac(int year, int day){
    if (year % 4 == 0) 
        return (float)day / 366;
    else
        return (float)day / 365;
}

int main(){
    printf("%f\n", yearfrac(2019, 300));
    printf("%f\n", yearfrac(2020, 100));
}