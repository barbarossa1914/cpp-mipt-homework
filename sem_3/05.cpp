#include <stdio.h>
#include <string.h>

int main() {
    int sum = 0;
    int a;
    while ((a = getchar()) != '\n')
        sum += a - '0';
    printf("%i", sum);
}