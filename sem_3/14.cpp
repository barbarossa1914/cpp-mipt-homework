#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    int k = atoi(argv[3]);
    int c;

    while ((c = fgetc(in)) != EOF) {
        if (isupper(c))
            c = 'A' + (c - 'A' + k) % 26;
        else if (islower(c))
            c = 'a' + (c - 'a' + k) % 26;
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
}