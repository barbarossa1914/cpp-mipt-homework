#include <stdio.h>

int main() {
	int n = 0;
	scanf_s("%i", &n);
	int l = 1;
	int max = n;
	printf("%i ", n);
	while (n != 1)
	{
		l += 1;
		if (n > max)
			max = n;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = 3 * n + 1;
		printf("%i ", n);
	}
	printf("Max = %i, Length = %i", max, l);

}
