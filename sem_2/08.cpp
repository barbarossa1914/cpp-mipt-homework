#include <stdio.h>

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i ++)
       {
        int a = arr[size - i - 1];
        arr[size - i - 1] = arr[i];
        arr[i] = a;
       }
}

int main() {
    int arr[100];
    int size;
    scanf("%i", &size);
    for (int i = 0; i < size; i ++)
        scanf("%i", &arr[i]);
    reverse(arr, size);
    for (int i = 0; i < size; i ++)
        printf("%i ", arr[i]);
}