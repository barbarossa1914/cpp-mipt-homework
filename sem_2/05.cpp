#include <stdio.h>
#include <math.h>

int print_binary(int number_10, int number_2, int n){
    if (number_10 == 0)
        return number_2;
    if (number_10 % 2 == 1)
        number_2 += pow(10, n);
    number_10 /= 2;
    n += 1;
    return print_binary(number_10, number_2, n);
}

int main() {
    int number;
    scanf("%i", &number);
    printf("%i", print_binary(number, 0, 0));
}