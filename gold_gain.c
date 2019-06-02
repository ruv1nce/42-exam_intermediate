// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 3
#define MAX(a,b) a > b ? a : b

int	gold_gain(int **mine, int n)
{
	int	x;
	int	y;
	int	z;
	int	result;

	if (!mine)
		return (0);
	if (n == 1)
		return (mine[0][0]);
	result = 0;
	/* start filling penultimate column (-1 for discount, -1 for last column */
	x = n - 1;
	while (--x >= 0)
	{
		y = -1;
		/* add biggest of three adjacent values from the next column to current value */
		while (++y < n)
		{
			/* check mine edges */
			if (y == 0)
				mine[y][x] += MAX(mine[y][x + 1], mine[y + 1][x + 1]);
			else if (y == n - 1)
				mine[y][x] += MAX(mine[y - 1][x + 1], mine[y][x + 1]);
			else
			{
				z = MAX(mine[y][x + 1], mine[y + 1][x + 1]);
				mine[y][x] += MAX(mine[y - 1][x + 1], z);
			}
		}
	}
	/* find biggest number in column 0 */
	y = -1;
	while (++y < n)
		result = (mine[y][0] > result ? mine[y][0] : result);
	return (result);
}

/*
int	main()
{
	int	x;
	int	y;
	int arr[SIZE][SIZE] = {
		{1, 2, 3},
		{3, 4, 8},
		{9, 6, 7}
	};
	int	**mine;

	mine = malloc(sizeof(*mine) * SIZE);
	y = -1;
	while (++y < SIZE)
		mine[y] = arr[y];
	printf("%i\n", gold_gain(mine, SIZE));
	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			printf("%2i ", arr[y][x]);
		printf("\n");
	}
}
*/
