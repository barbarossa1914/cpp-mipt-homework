#include <stdio.h>

int is_little_endian() {
    int x = 1;
    unsigned char* p = (unsigned char*)&x;
    
    if (p[0] == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    if (is_little_endian()) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}