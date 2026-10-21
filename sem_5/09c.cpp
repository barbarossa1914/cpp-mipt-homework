#include <stdio.h>

#define SIZE 1000000000

int main() {
    char data[SIZE];

    printf("data allocated on stack\n");
    data[0] = 'A';
    printf("first char = %c\n", data[0]);
    return 0;
}