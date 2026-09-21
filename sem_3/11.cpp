#include <stdio.h>
#include <string.h>

void safe_cpy(char a[], size_t k, const char b[]){
    for (size_t i = 0; i < k - 1; i++)
    {
        a[i] = b[i];
    }
    a[k-1] = '\0';
}

int main(){
    char a[10] = "mouse";
    char b[50] = "LargeElephant";
    size_t k = 10;
    safe_cpy(a, 10, b);
    printf("%s", a);
}