#include <stdio.h>

int main() {
    int a[1000];
    int n;
    scanf_s("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf_s("%i", &a[i]);
    int new_n = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            a[new_n] = a[i];
            new_n++;
        }
    }

    n = new_n;
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
}
