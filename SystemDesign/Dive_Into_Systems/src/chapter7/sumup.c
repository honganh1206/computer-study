#include <stdio.h>

int sumUpWhileLoop(int n)
{
	int total = 0;
	int i = 1;

	while (i <= n)
	{
		total += 1;
		i++;
	}

	return total;
}

int sumUpForLoop(int n)
{
	int total = 0;

	for (int i = 1; i <= n; i++)
	{
		total += 1;
	}

	return total;
}

int main(void)
{
	int x;
	x = sumUpWhileLoop(10);
	printf("%d\n", x);
	return 0;
}
