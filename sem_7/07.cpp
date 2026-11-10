#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* f = fopen(argv[1], "rb");

    fseek(f, 0, SEEK_END);
    printf("%ld\n", ftell(f));

    fclose(f);
}