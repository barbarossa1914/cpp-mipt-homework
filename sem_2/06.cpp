#include <stdio.h>

int trib(int number){
    int t_0 = 0;
    int t_1 = 0;
    int t_2 = 1;
    int t_new = 0;
    for (int i = 0; i <= (number - 3); i ++)
    {
        t_new = t_0 + t_1 + t_2;
        t_0 = t_1;
        t_1 = t_2;
        t_2 = t_new;
    }
    return t_2;
}

int main() {
    printf("%i", trib(38));
}