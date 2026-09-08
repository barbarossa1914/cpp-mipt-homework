#include <stdio.h>
#include <cmath>

int main() {
	int n = 0;
	int m = 0;
	scanf_s("%i %i", &n, &m);
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			sum += pow(-1, (i + j)) * i * j;
	}
	printf("%i", sum);
}
