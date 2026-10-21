#include <stdlib.h>
#include <stdio.h>


float* get_geometric_progression(float a, float r, int n) {
    float* arr = (float*)malloc(n * sizeof(float));
    float current = a;
    for (int i = 0; i < n; ++i) {
        arr[i] = current;
        current *= r;
    }
    return arr;
}

int main() {
    int n = 10;
    float* arr = get_geometric_progression(1, 3, n);

    for (int i = 0; i < n; ++i) {
        printf("%.0f ", arr[i]);
    }
    printf("\n");

    free(arr);
}