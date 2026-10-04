#include <stdio.h>

int exchange(int* pa, int b){
    int old_a = *pa;
    *pa = b;
    return old_a;
}

int main(){
    int a = 10;
    printf("%i\n", exchange(&a, 20));  // Напечатает 10
    printf("%i\n", a);                 // Напечатает 20
    return 0;
}