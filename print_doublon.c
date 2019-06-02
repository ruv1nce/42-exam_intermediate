#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	if (a && b && na && nb)
	{
		for (int i = 0, j = 0, flag = 0; i < na && j < nb;)
		{
			if (a[i] < b[j])
				i++;
			else if (b[j] < a[i])
				j++;
			else
			{
				if (!flag)
				{
					printf("%i", a[i]);
					flag = 1;
				}
				else
					printf(" %i", a[i]);
				i++;
				j++;
			}
		}
	}
	printf("\n");
}
