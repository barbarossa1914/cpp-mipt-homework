#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* f = fopen(argv[1], "rb");
    fseek(f, -3, SEEK_END);
    for (int i = 0; i < 3; i++) {
        printf("%c", fgetc(f));
    }
    fclose(f);
}