#include <stdio.h>

int main() {
	int n = 0;
	scanf_s("%i", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; i += 1)
		scanf_s("%i", &arr[i]);
	for (int i = 0; i < n; i += 1)
		printf("%i ", arr[i]);
	for (int i = 0; i < n; i += 1)
		printf("%i ", arr[i]);
	delete[] arr;
}
