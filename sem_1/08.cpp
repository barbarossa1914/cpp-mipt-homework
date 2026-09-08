#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	scanf_s("%i %i %i", &a, &b, &c);
	int start = a;
	while (start % c != 0)
		start += 1;
	printf("%i ", start);
	while ((start + c) <= b)
	{
		start += c;
		printf("%i ", start);
	}
}
