#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EVEN(a) (a >= '0' && a <= '9') && !((a - '0') % 2)
#define ODD(a) (a >= '0' && a <= '9') && (a - '0') % 2

void	stringcopy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}

/* iterate by deleting last digit */
void	permute(char *dup, char *sub, int even, int odd, int len)
{
	/* erase last digit (at first run it's already \0) */
	dup[len] = 0;
	/* if even == odd, save current string in result */
	if (even == odd && (int)strlen(sub) < len)
		stringcopy(sub, dup);
	else
	{
		/* while len != 0 and there's chance to find a solution */
		if (len && even && odd)
		{
			/* check if we lose an even or an odd digit */
			if (EVEN(dup[len - 1]))
				permute(dup, sub, even - 1, odd, len - 1);
			else if (ODD(dup[len - 1]))
				permute(dup, sub, even, odd - 1, len - 1);
			else
				permute(dup, sub, even, odd, len - 1);
		}
	}
}

char	*longest_subarray(char *arr)
{
	char	*sub;
	char	*dup;
	int		len;
	int		even;
	int		odd;
	int		i;

	if (!arr)
		return (NULL);
	if (!(len = strlen(arr)))
		return (NULL);
	if (!(sub = malloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i <= len)
		sub[i] = 0;
	even = 0;
	odd = 0;
	i = -1;
	while (arr[++i])
	{
		if (EVEN(arr[i]))
			even++;
		else if (ODD(arr[i]))
			odd++;
	}
	/* iterate by deleting first digit */
	while (*arr)
	{
		/* create a duplicate string so it can be edited in permute */
		if (!(dup = malloc(len + 1)))
			return (NULL);
		stringcopy(dup, arr);
		permute(dup, sub, even, odd, len);
		/* check if we lose an even or an odd digit */
		if (EVEN(*arr))
			even--;
		else if (ODD(*arr))
			odd--;
		arr++;
		len--;
		free(dup);
	}
	return (sub);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", longest_subarray(argv[1]));
}
