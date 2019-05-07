#include <stdlib.h>
#include <stdio.h>

void	print_grid(int ht, int size, char grid[ht][size])
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

int pour_water(int *hist, int size, int ht)
{
	int		x;
	int		y;
	char	grid[ht][size];
	int		flag;
	int		water;

	/* draw bars and empty space*/
	/* iterate through bars */
	x = -1;
	while (++x < size)
	{
		/* iterate through bar height */
		y = -1;
		while (++y < ht)
		{
			if (y < hist[x])
				grid[ht - 1 - y][x] = '#';
			else
				grid[ht - 1 - y][x] = ' ';
		}
	}
	print_grid(ht, size, grid);
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
	print_grid(ht, size, grid);
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

int	volume_histogram(int *histogram, int size)
{
	int		i;
	int		ht;

	if (!histogram || size < 3)
		return (0);
	/* find max bar height */
	ht = 0;
	i = -1;
	while (++i < size)
		if (ht < histogram[i])
			ht = histogram[i];
	if (ht == 0)
		return (0);
	return (pour_water(histogram, size, ht));
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
