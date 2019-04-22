#include <stdlib.h>
#include <stdio.h>

void	print_grid(char **grid, int ht, int size)
{
	int		x;
	int		y;

	y = -1;
	while (++y < ht)
	{
		x = -1;
		while (++x < size)
			printf("%c ", grid[y][x]);
		printf("\n");
	}
	printf("\n");
}

int	volume_histogram(int *histogram, int size)
{
	int		x;
	int		y;
	int		ht;
	char	**grid;
	int		flag;
	int		water;

	if (!histogram || size < 3)
		return (0);
	/* find max bar height */
	ht = 0;
	x = -1;
	while (++x < size)
		if (ht < histogram[x])
			ht = histogram[x];
	if (ht == 0)
		return (0);
	/* allocate grid */
	grid = malloc(sizeof(*grid) * ht);
	y = -1;
	while (++y < ht)
		grid[y] = malloc(sizeof(**grid) * size);
	/* draw bars and empty space*/
	/* iterate through bars */
	x = -1;
	while (++x < size)
	{
		/* iterate through bar height */
		y = -1;
		while (++y < ht)
		{
			if (y < histogram[x])
				grid[ht - 1 - y][x] = '#';
			else
				grid[ht - 1 - y][x] = ' ';
		}
	}
	print_grid(grid, ht, size);
	/* mark all spaces that can't hold water (ain't got two walls) */
	y = -1;
	while (++y < ht)
	{
		/* go left to right */
		flag = 0;
		x = -1;
		while (++x < size)
		{
			if (grid[y][x] == '#')
				flag = 1;
			else
				if (!flag)
					grid[y][x] = 'X';
		}
		/* go right to left */
		flag = 0;
		while (--x >= 0)
		{
			if (grid[y][x] == '#')
				flag = 1;
			else
				if (!flag)
					grid[y][x] = 'X';
		}
	}
	print_grid(grid, ht, size);
	water = 0;
	y = -1;
	while (++y < ht)
	{
		x = -1;
		while (++x < size)
		{
			if (grid[y][x] == ' ')
				water++;
		}
	}
	return (water);
}

int	main(int argc, char **argv)
{
	int	*hist;
	int	i;

	if (argc > 1)
	{
		hist = malloc(sizeof(*hist) * (argc - 1));
		i = 0;
		while (++i < argc)
			hist[i - 1] = atoi(argv[i]);
		printf("%i\n", volume_histogram(hist, argc - 1));
	}
}
