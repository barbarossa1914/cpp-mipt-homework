#include <stdio.h>

// Вспомогательная функция для печати памяти
void print_memory(const char* name, void* ptr, size_t size) {
    printf("%-20s: ", name);
    unsigned char* p = (unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");
}

int main() {
    int a = 0x11223344;
    int b = 1000000000;
    int c = 65535;
    int d = -1;
    int array[3] = {10, 2000, 65535};
    char str[9] = "Cat\nDog\n";
    float x = 1.0f;

    print_memory("int a", &a, sizeof(int));
    print_memory("int b", &b, sizeof(int));
    print_memory("int c", &c, sizeof(int));
    print_memory("int d", &d, sizeof(int));
    print_memory("int array", &array, sizeof(array));
    print_memory("char str", &str, sizeof(str));
    print_memory("float x", &x, sizeof(float));

    return 0;
}