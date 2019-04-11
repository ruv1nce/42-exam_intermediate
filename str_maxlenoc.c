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

char	*lcsubstr_mult(char **s, int cnt, int maxlen)
{
	int		i;
	int		len;
	int		lencurrent;
	int		success;
	int		word;
	char	*lcs;
	char	*lcscurrent;
	char	*tmp;

	lencurrent = 0;
	lcs = malloc(maxlen + 1);
	lcs[maxlen] = 0;
	lcscurrent = malloc(maxlen + 1);
	lcscurrent[maxlen] = 0;
	i = -1;
	/* iterate on letters of the first word */
	while (s[0][++i])
	{
		/* if this is not the first-letter-loop, change lcs address so that lcscurrent won't get erased */
		if (len)
			lcs = tmp;
		len = 0;
		/* increase lcs len if the previous lcs was a success */
		success = 1;
		while (success && ++len <= maxlen && s[0][i + len - 1])
		{
			/* add next letter to lcs */
			lcs[len - 1] = s[0][i + len - 1];
			lcs[len] = 0;
			word = 0;
			/* iterate on words */
			while (++word < cnt)
			{
				if (!(ft_strstr(s[word], lcs)))
				{
					success = 0;
					break ;
				}
			}
		}
		/* decrement len back to the state that was before last while check */
		len--;
		/* if no success, delete last letter */
		if (!success)
			lcs[len] = 0;
		/* if new substring is longer than previously found, save it in lcscurrent */
		if (len > lencurrent)
		{
			lencurrent = len;
			tmp = lcscurrent;
			lcscurrent = lcs;
		}
	}
	return (lcscurrent);
}

int		main(int argc, char **argv)
{
	char	*lcs;

	if (argc > 1)
	{
		lcs = lcsubstr_mult(argv + 1, (argc - 1), ft_strlen(argv[1]));
		while (*lcs)
		{
			write(1, lcs, 1);
			lcs++;
		}
	}
	write(1, "\n", 1);
}
