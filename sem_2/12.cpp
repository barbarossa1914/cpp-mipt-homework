#include <stdio.h>
#define MAX 100

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k){
    int B[MAX][MAX];
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = A[i][j];
    for (int s = 0; s < k - 1; s++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0;
                for (int l = 0; l < n; l++)
                    C[i][j] += A[i][l] * B[l][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = C[i][j];
    }
}

int main(){
    int A[MAX][MAX] = {{7, 7, 2}, {1, 8, 3}, {2, 1, 6}};
    int C[MAX][MAX];
    power(A, C, 3, 4);
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
            printf("%i ", C[i][j]);
    }
}