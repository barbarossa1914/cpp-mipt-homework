#include <stdio.h>
#include <string.h>

void is_palindrom(const char *a){
    size_t l1 = strlen(a);
    for (size_t i = 0; i < l1 / 2 + 1; i++)
    {
        if (a[i] == a[l1 - i - 1])
            continue;
        else
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main(){
    is_palindrom("abba");
    is_palindrom("assba");
}