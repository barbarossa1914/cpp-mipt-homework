#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    char* result = (char*)malloc(len_a + len_b);

    strcpy(result, a);
    strcat(result, b);

    return result;
}

int main() {
    char* s = concat("Hello, ", "world!");
    printf("%s\n", s);
    free(s);
}