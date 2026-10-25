#include <stdio.h>

int main(){
    {
    #ifdef Dog
    printf("Dog");
    #else
    printf("Not dog");
    #endif
    }
}