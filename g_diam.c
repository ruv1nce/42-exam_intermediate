#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define NUM(x) x >= '0' && x <= '9'

static int	lp;

int		atoi_edge(char **s)
{
	int	sum;

	sum = 0;
	while (NUM(**s))
	{
		sum *= 10;
		sum += **s - '0';
		(*s)++;
	}
	if (**s)
		(*s)++;
	return (sum);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 10)
		ft_putnbr(n/10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	find_lp(int max, uint8_t grid[max][max],uint8_t path[max], int y, int len)
{
	int	x;

	/* mark vertix y as visited */
	path[y] = 1;
	/* iterate through columns */
	x = -1;
	while (++x < max)
	{
		/* if edge found and the paired vertix isn't yet visited,
			increment len for this edge and run recursion for
			the corresponding paired vertix (a.k.a. row) */
		if (grid[y][x] && !path[x])
		{
			if (lp < len + 1)
				lp = len + 1;
			find_lp(max, grid, path, x, len + 1);
		}
	}
	/* backtrack */
	path[y] = 0;
}

void	graph(int max, char *s)
{
	uint8_t	grid[max][max];
	uint8_t	path[max];
	int		x;
	int		y;

	/* inititialize grid and path */
	y = -1;
	while (++y < max)
	{
		x = -1;
		while (++x < max)
			grid[y][x] = 0;
	}
	x = -1;
	while (++x < max)
		path[x] = 0;
	/* fill the edges */
	while (*s)
	{
		y = atoi_edge(&s);
		x = atoi_edge(&s);
		grid[y][x] = 1;
		grid[x][y] = 1;
	}
	lp = 2;
	/* iterate through rows */
	y = -1;
	while (++y < max)
		find_lp(max, grid, path, y, 1);
}

int		main(int argc, char **argv)
{
	char	*s;
	int		max;
	int		i;

	if (argc == 2)
	{
		/* find biggest vertix number */
		s = &argv[1][0];
		max = 0;
		while (*s)
		{
			i = atoi_edge(&s);
			max = (max < i) ? i : max;
		}
		/* increment max +1 for [0] position of the arrays */
		max++;
		graph(max, &argv[1][0]);
		ft_putnbr(lp);
	}
	write(1, "\n", 1);
}
