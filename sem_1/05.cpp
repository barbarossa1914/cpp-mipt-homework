#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	scanf_s("%i", &n);
	int max = INT_MIN;
	int c = 1;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a > max)
		{
			max = a;
			c = 1;
		}
		else if (a == max)
			c += 1;
	}
	printf("Max = %i, number = %i\n", max, c);
}
