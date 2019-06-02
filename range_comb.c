#include <stdlib.h>
// #include <stdio.h>

static int	count;

int		factorial(int n)
{
	int	fac;

	fac = n;
	while (--n > 1)
		fac *= n;
	return (fac);
}

void	permute(int **perms, int *sol, unsigned char *dp, int n, int i)
{
	int	k;

	/* save solution to perms upon reaching last int in range */
	if (i == n)
	{
		k = -1;
		while (++k < n)
			perms[count][k] = sol[k];
		/* increment perms count */
		count++;
	}
	else
	{
		/* iterate through integers from 0 to n-1 */
		k = -1;
		while (++k < n)
		{
			/* if int k is absent from current solution, add it to sol
			 * and mark this fact in dp, then iterate through sol indices */
			if (!dp[k])
			{
				sol[i] = k;
				dp[k] = 1;
				permute(perms, sol, dp, n, i + 1);
				/* after finding solution, unmark k index in dp */
				dp[k] = 0;
			}
		}
	}
}

int		**range_comb(int n)
{
	int				**perms;
	int				sol[n];
	unsigned char	dp[n];
	int				combs;
	int	i;

	if (n < 1)
		return (NULL);
	i = -1;
	while (++i < n)
		dp[i] = 0;
	combs = factorial(n);
	if (!(perms = malloc(sizeof(*perms) * (combs + 1))))
		return (NULL);
	/* NULL-terminated array */
	perms[combs] = NULL;
	while (--combs >= 0)
		if (!(perms[combs] = malloc(sizeof(**perms) * n)))
			return (NULL);
	permute(perms, sol, dp, n, 0);
	return (perms);
}

/*
int		main(int argc, char **argv)
{
	int	**perms;
	int	n;
	int	i;
	int	j;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		perms = range_comb(n);
		j = -1;
		while (perms[++j])
		{
			i = -1;
			while (++i < n)
				printf("%i ", perms[j][i]);
			printf("\n");
		}
	}
}
*/
