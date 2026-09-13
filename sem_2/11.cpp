#include <stdio.h>
#define MAX 100

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    }
}

int main() {
    float A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, n2;
    FILE *f;

    f = fopen("combinedAB.txt", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%f", &A[i][j]);

    fscanf(f, "%d", &n2);
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n2; j++)
            fscanf(f, "%f", &B[i][j]);
    fclose(f);

    multiply(A, B, C, n);

    f = fopen("result.txt", "w");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fprintf(f, "%g ", C[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);

    return 0;
}