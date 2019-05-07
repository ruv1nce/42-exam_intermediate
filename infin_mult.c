#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*mult(char *first, char *second, int len1, int len2)
{
	int		*res;
	int		lenres;
	int		offset;
	int		j;
	int		k;
	char	*out;
	int		carry;

	lenres = len1 + len2;
	res = malloc(sizeof(*res) * lenres);
	out = malloc(lenres + 1);
	out[lenres] = 0;
	k = -1;
	while (++k < lenres)
	{
		res[k] = 0;
		out[k] = 0;
	}
	/* iterate through *first digits from end to start, with each
	   iteration increase offset to store results in res with offset */
	offset = 0;
	while (--len1 >= 0)
	{
		/* iterate through *second digits from end to start using j;
		   save multiplication results right to left in res */
		j = len2;
		k = lenres;
		while (--j >= 0)
		{
			k--;
			res[k - offset] += (first[len1] - '0') * (second[j] - '0');
		}
		offset++;
	}
	k = lenres;
	carry = 0;
	while (--k >= 0)
	{
		j = res[k] + carry;
		out[k] += j % 10 + '0';
		carry = j / 10;
	}
	while (*out == '0')
		out++;
	return (out);
}

int		main(int argc, char **argv)
{
	char	*res;
	int		sign1;
	int		sign2;

	sign1 = 0;
	sign2 = 0;
	if (argc == 3)
	{
		if (argv[1][0] == '-')
		{
			sign1 = -1;
			(*(argv + 1))++;
		}
		if (argv[2][0] == '-')
		{
			sign2 = -1;
			(*(argv + 2))++;
		}
		res = mult(argv[1], argv[2], ft_strlen(argv[1]), ft_strlen(argv[2]));
		if (*res && ((!sign1 && sign2) || (sign1 && !sign2)))
			write(1, "-", 1);
		if (*res)
			write(1, res, ft_strlen(res));
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
}
