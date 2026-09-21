#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Wrong number of arguments!\n");
        return 1;
    }

    int a;
    int b;
    char op;
    if (sscanf(argv[1], "%i %c %i", &a, &op, &b) != 3) {
        printf("Error: Wrong format!\n");
        return 1;
    }

    if (op == '+') {
        printf("%i\n", a + b);
    } else if (op == '-') {
        printf("%i\n", a - b);
    } else if (op == '*') {
        printf("%i\n", a * b);
    } else if (op == '/') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        printf("%i\n", a / b);
    } else if (op == '%') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        printf("%i\n", a % b);
    } else {
        printf("Error: Invalid operator!\n");
        return 1;
    }
}