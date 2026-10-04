#include <stdio.h>

void set_characters(char* begin, char* end, char c){
    size_t len = end - begin;
    for (size_t i=0; i < len; i++){
        begin[i] = c;
    }
}

int main()
{
    char s[] = "Sapere Aude";
    
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s);  // Напечатает Sabbabbbude
    
    set_characters(s, &s[4], 'a');
    printf("%s\n", s);  // Напечатает aaaabbbude
    
    return 0;
}