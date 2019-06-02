#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

int ft_strstr(char *s, char *lcs, int end)
{
	int success = 0;

	/* iterate through haystack if no success*/
	for (int i = 0; s[i] && !success; i++)
	{
		/* iterate through lcs */
		success = 1;
		for (int j = 0; j <= end; j++, i++)
		{
			if (s[i] != lcs[j])
			{
				success = 0;
				break;
			}
		}
	}
	return (success);
}

int main(int argc, char **argv)
{
	/* initialize lcs_start and _end in such a way so that (_end - _start) < 0 */
	int maxlen, lcs_start = 1, lcs_end = 0;

	if (argc > 1)
	{
		maxlen = ft_strlen(argv[1]);
		/* iterate through first letters of the first string */
		for (int start = 0, success = 1; start < maxlen; start++)
		{
			success = 1;
			/* grow lcs if successfully found previous one in all strings */
			for (int end = start; end < maxlen && success; end++)
			{
				success = 1;
				/* iterate through strings to find the current lcs */
				for (int i = 2; i < argc && success; i++)
				{
					if (!(ft_strstr(argv[i], &argv[1][start], end - start)))
					{
						success = 0;
						break;
					}
				}
				/* if lcs not found in all strings, break to outer cycle */
				if (!success)
					break;
				/* if found current lcs in all strings, and its longer than
                 *      prevoius lcs, save new lcs */
				if (end - start > lcs_end - lcs_start)
				{
					lcs_start = start;
					lcs_end = end;
				}
			}
		}
		/* if (_end - _start) >= 0 then a valid lcs was found */
		if (lcs_end - lcs_start >= 0)
			write(1, &argv[1][lcs_start], lcs_end - lcs_start + 1);
	}
	write(1, "\n", 1);
}
