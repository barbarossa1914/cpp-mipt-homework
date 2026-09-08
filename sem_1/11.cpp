#include <stdio.h>

int main() {
	int n = 0;
	int m = 0;
	scanf_s("%i %i", &n, &m);
	int* arr = new int[n * m];
	for (int i = 0; i < n * m; i++)
		scanf_s("%i", &arr[i]);
	int* cols = new int[m];
	for (int i = 0; i < m; i++)
		cols[i] = 0;
	for (int i = 0; i < n * m; i++)
	{
		int id = i % m;
		cols[id] += arr[i];
	}
	for (int i = 0; i < m; i++)
		printf("%i ", cols[i]);
	delete[] arr;
	delete[] cols;

}