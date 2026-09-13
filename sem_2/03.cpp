#include <stdio.h>

void print_even(int l, int r){
    for (int i = l; i <=r; i ++)
       {
        if (i % 2 == 0)
            printf("%i ", i);
       }
}

int main() {
    int l;
    int r;
    scanf("%i%i", &l, &r);
    print_even(l, r);
}