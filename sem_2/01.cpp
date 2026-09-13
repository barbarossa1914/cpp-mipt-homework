#include <stdio.h>

int cube(int number) {
    return number * number * number;
}

int main() {
    printf("%i\n", cube(5));
}