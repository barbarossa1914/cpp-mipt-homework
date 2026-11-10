#include <stdio.h>
#include <string.h>

union Data {
    int nums[4];
    char str[16];
};

int main() {
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};

    char* p = (char*)a;
    printf("%s", p);

    union Data d;
    for (int i = 0; i < 4; i++) {
        d.nums[i] = a[i];
    }
    printf("%s", d.str);

    char str[17] = {0};
    memcpy(str, a, sizeof(a));
    printf("%s", str);
}