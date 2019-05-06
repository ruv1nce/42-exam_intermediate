#include <unistd.h>
#include <stdlib.h>

int		ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	char	*needorig;

	needorig = (char *)needle;
	if (!*needle)
		return (1);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			ptr = (char *)haystack;
			while (*haystack == *needle && *needle)
			{
				haystack++;
				needle++;
			}
			if (!*needle)
				return (1);
			haystack = ptr;
			needle = needorig;
		}
		haystack++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*lcsubstr_mult(char **s, int cnt, int firstwordlen)
{
	int		i;
	int		len;
	int		lenprev;
	int		success;
	int		word;
	char	*lcs;
	char	*lcsprev;
	char	*tmp;

	lenprev = 0;
	/* lcs can't be longer than the first word len */
	lcs = malloc(firstwordlen + 1);
	lcs[firstwordlen] = 0;
	lcsprev = malloc(firstwordlen + 1);
	lcsprev[firstwordlen] = 0;
	/* iterate through letters of the first word */
	i = -1;
	while (s[0][++i])
	{
		len = 0;
		success = 1;
		/* if the previous lcs was a success and there are more letters in the first word, grow lcs */
		while (success && ++len <= firstwordlen && s[0][i + len - 1])
		{
			/* add next letter to lcs */
			lcs[len - 1] = s[0][i + len - 1];
			lcs[len] = 0;
			/* iterate through words */
			word = 0;
			while (success && ++word < cnt)
			{
				if (!(ft_strstr(s[word], lcs)))
					success = 0;
			}
		}
		/* decrement len back to the state before last while loop condition check */
		len--;
		/* if no success, delete last letter */
		if (!success)
			lcs[len] = 0;
		/* if new substring is longer than previously found, switch lcs and lcsprev */
		if (len > lenprev)
		{
			lenprev = len;
			tmp = lcsprev;
			lcsprev = lcs;
			lcs = tmp;
		}
	}
	return (lcsprev);
}

int		main(int argc, char **argv)
{
	char	*lcs;

	if (argc > 1)
	{
		lcs = lcsubstr_mult(argv + 1, argc - 1, ft_strlen(argv[1]));
		while (*lcs)
		{
			write(1, lcs, 1);
			lcs++;
		}
	}
	write(1, "\n", 1);
}
