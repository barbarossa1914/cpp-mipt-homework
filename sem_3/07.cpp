#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(const char *str, int k){
    size_t l1 = strlen(str);
    char new_str[100];
    for (size_t i = 0; i < l1; i++)
    {
        int a = str[i];
        if (isalpha(a))
        {
            if (isupper(a))
            {
                new_str[i] = 'A' + (a - 'A' + k)%26;
            }
            else if (islower(a))
            {
                new_str[i] = 'a' + (a - 'a' + k)%26;
            }
        }
        else
            new_str[i] = str[i];
    }
    printf("%s\n", new_str);
}
int main(){
    encrypt("Green Terra", 13);
}