#include <stdlib.h>
#include <unistd.h>

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

char	*infin_add(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		carry;
	int		tmp;
	int		lenres;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	/* the addition result can be at most (longer component len + 1) long */
	lenres = (len1 > len2) ? len1 + 1 : len2 + 1;
	res = malloc(lenres + 1);
	res[lenres] = 0;
	carry = 0;
	len1--;
	len2--;
	/* add digits decade by decade, carrying 1 if previous result was > 10 */
	while (len1 >= 0 || len2 >= 0)
	{
		tmp = carry;
		if (len1 >= 0)
			tmp += s1[len1] - '0';
		if (len2 >= 0)
			tmp += s2[len2] - '0';
		if (tmp >= 10)
			carry = 1;
		else
			carry = 0;
		res[--lenres] = tmp % 10 + '0';
		len1--;
		len2--;
	}
	if (carry)
		res[--lenres] = carry + '0';
	return (&res[lenres]);
}
char	*infin_mult(char *s1, char *s2)
{
	int		len1;
	int		len1tmp;
	int		len2;
	int		carry;
	int		tmp;
	int		lenmult;
	int		lenres;
	int		coeff;
	char	*res;
	char	*mult;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	/* the multiplication result can be at most (len1 + len2) long */
	lenmult = len1 + len2;
	mult = malloc(lenmult + 1);
	tmp = -1;
	while (++tmp < lenmult)
		mult[tmp] = 0;
	carry = 0;
	len1--;
	len2--;
	coeff = 0;
	lenres = lenmult;
	/* multiply s1 by s2's digits */
	while (len2 >= 0)
	{
		len1tmp = len1;
		lenmult = lenres - coeff;
		while (len1tmp >= 0)
		{
			tmp = (s1[len1tmp] * s2[len2] + carry);
			mult[--lenmult] = tmp % 10 + '0';
			carry = tmp / 10;
			len1tmp--;
		}
		len2--;
		coeff++;
		res = infin_add(res, mult);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	char	*result;
	int		neg;

	if (argc == 3)
	{
		/* check if the result should be negative */
		neg = ((argv[1][0] == '-' && argv[2][0] != '-') || (argv[1][0] != '-' && argv[2][0] == '-')) ? 1 : 0;
		/* move argv pointers past '-' if any */
		*(argv + 1) = (argv[1][0] == '-') ? *(argv + 1) + 1 : *(argv + 1);
		*(argv + 2) = (argv[2][0] == '-') ? *(argv + 2) + 1: *(argv + 2);
		result = infin_mult(argv[1], argv[2]);
		if (neg)
			write(1, "-", 1);
		write(1, result, ft_strlen(result));
		write(1, "\n", 1);
	}
}
