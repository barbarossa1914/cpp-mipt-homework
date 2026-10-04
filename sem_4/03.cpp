#include <stdio.h>

void cube(float* px){
    *px = *px * *px * *px;
    return;
}

int main(){
    float b = 7.8;
    float* p = &b;
    cube(p);
    printf("%f", b);
}