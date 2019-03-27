#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int	first;

	i = 0;
	j = 0;
	first = 1;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (first == 1)
			{
				first = 0;
				printf("%i", a[i]);
			}
			else
				printf(" %i", a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else if (a[i] > b[j])
			j++;
	}
	printf("\n");
}

int		main()
{
	int	a[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int	na = 11;
	int	b[] = {4,  4,  5,  6,  7, 16,  40,  75};
	int	nb = 8;
	print_doublon(a, na, b, nb);
}
