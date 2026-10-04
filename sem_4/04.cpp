#include <stdio.h>

void mult2_a(int* p, size_t n){
    for (size_t i=0; i<n; ++i){
        *(p+i) *= 2;
    }
    return;
}

void mult2_b(int* p, size_t n){
    for (size_t i=0; i<n; ++i){
        p[i] *= 2;
    }
    return;
}

int main(){
    int arr[3] = {1, 2, 3};
    int* p = &arr[0];
    mult2_a(p, 3);
    printf("%i", arr[1]);
    mult2_b(p, 3);
    printf("%i", arr[1]);
}