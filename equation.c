#include <stdio.h>

void	equation(int n)
{
	int	a;
	int	b;
	int	c;
	int	add;

	a = 0;
	while ((a * 10) + a <= n && a < 10)
	{
		add = n - (a * 10 + a);
		b = add % 10;
		c = add / 10;
		if (b < 10 && c < 10)
			printf("A = %i, B = %i, C = %i\n", a, b, c);
		a++;
	}
}

int		main()
{
	printf("42\n");
	equation(42);
	printf("\n111\n");
	equation(111);
	printf("\n0\n");
	equation(0);
}
