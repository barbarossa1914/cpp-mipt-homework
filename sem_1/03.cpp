#include <stdio.h>

int main() {
	int a = 0;
	scanf_s("%i", &a);
	if (a % 2 == 0 && ((0 <= a && a <= 20) || (100 < a && a < 200)))
		printf("Yes");
	else
		printf("No");
}
