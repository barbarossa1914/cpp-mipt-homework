#include <stdio.h>

int count_even() {
    int arr[100];
    int size;
    int c = 0;
    scanf("%i", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%i", &arr[i]);
        if (arr[i] % 2 == 0)
            c ++;
    }
        
    return c;
}

int main() {
    printf("%i", count_even());
}