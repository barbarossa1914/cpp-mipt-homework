#include <stdio.h>

int main() {
	int a = 0;
	scanf_s("%i", &a);
	for (int i = 0; i <= a; i++)
		printf("%3i->%3i->%3i\n", i, i * i, i * i * i);
}
