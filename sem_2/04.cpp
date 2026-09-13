#include <stdio.h>

int sum_of_digits(int number){
    int sum = 0;

    while (number != 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    return sum;
}

int sum_of_digits_rec(int number, int sum){

    if (number == 0)
        return sum;
    sum += number % 10;
    number /= 10;
    return sum_of_digits_rec(number, sum);
}

int main() {
    int number;
    scanf("%i", &number);
    printf("%i", sum_of_digits_rec(number, 0));
}
