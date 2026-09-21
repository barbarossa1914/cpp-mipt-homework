#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    char b[100];
    scanf("%s %s", a, b);
    size_t l1 = strlen(a);
    size_t l2 = strlen(b);
    size_t c = 0;
    if (l1 > l2)
    {
        while (c < l2)
        {
            printf("%c", a[c]);
            printf("%c", b[c]);
            c++;
        }
        while (c < l1)
        {
            printf("%c", a[c]);
            c++;
        }
    }
    else
    {
        while (c < l1)
        {
            printf("%c", a[c]);
            printf("%c", b[c]);
            c++;
        }
        while (c < l2)
        {
            printf("%c", b[c]);
            c++;
        }
    }
}