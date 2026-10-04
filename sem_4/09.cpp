#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used) {
    int seen[26] = {0};
    
    for (const char* p = str; *p != '\0'; ++p) {
        if (isalpha(*p)) {
            char lower = tolower(*p);
            seen[lower - 'a'] = 1;
        }
    }
    
    int j = 0;
    for (int i = 0; i < 26; ++i) {
        if (seen[i]) {
            used[j++] = 'a' + i;
        }
    }
    used[j] = '\0';
}

int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);

    return 0;
}