#include <stdio.h>
#include <string.h>

void trim_after_first_space(char *s) {
    size_t l1 = strlen(s);
    for (size_t i = 0; i < l1; i++) {
        if (s[i] == ' ') {
            s[i] = '\0';
            return;
        }
    }
}

int main() {
    char a[] = "Cats and Dogs";
    printf("%s\n", a);
    trim_after_first_space(a);
    printf("%s\n", a);
    return 0;
}