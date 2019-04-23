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

int		ft_strcmp(char*s2, char *s1)
{
	while (*s2 && *s1 && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

char	*infin_sub(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		carry;
	int		lenres;
	int		neg;
	int		tmp;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	neg = 0;
	/* if s2 > s1, the result will be negative and we have to swap s1 and s2
	 * we will use res pointer as a tmp*/
	if (len2 > len1)
		neg = 1;
	else if (len2 == len1)
		if (ft_strcmp(s2, s1) > 0)
			neg = 1;
	if (neg)
	{
		res = s1;
		s1 = s2;
		s2 = res;
		/* to avoid confusion we will also swap lens using lenres as tmp */
		lenres = len1;
		len1 = len2;
		len2 = lenres;
	}
	/* the subtraction result can be at most (longer component len + 1 [for '-']) long */
	lenres = (len1 > len2) ? len1 + 1 : len2 + 1;
	res = malloc(lenres + 1);
	res[lenres] = 0;
	carry = 0;
	len1--;
	len2--;
	/* subtract digits decade by decade, carrying -1 if previous result was < 0 */
	while (len1 >= 0 || len2 >= 0)
	{
		tmp = carry;
		if (len1 >= 0)
			tmp += s1[len1] - '0';
		if (len2 >= 0)
			tmp -= s2[len2] - '0';
		if (tmp < 0)
		{
			carry = -1;
			tmp += 10;
		}
		else
			carry = 0;
		res[--lenres] = tmp % 10 + '0';
		len1--;
		len2--;
	}
	/* skip leading zeroes, if any */
	while (res[lenres] == '0')
		lenres++;
	/* add '-' if result should be negative */
	if (neg)
		res[--lenres] = '-';
	return (&res[lenres]);
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
	/* add digits decade by decade, carrying 1 if previous result was > 9 */
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

int	main(int argc, char **argv)
{
	char	*result;

	if (argc == 3)
	{
		if (argv[1][0] == '-')
		{
			/* if both are negative */
			if (argv[2][0] == '-')
			{
				result = infin_add(&argv[1][1], &argv[2][1]);
				write(1, "-", 1);
				write(1, result, ft_strlen(result));
				write(1, "\n", 1);
			}
			/* if only first is negative */
			else
			{
				result = infin_sub(argv[2], &argv[1][1]);
				write(1, result, ft_strlen(result));
				write(1, "\n", 1);
			}
		}
		/* if only second is negative */
		else if (argv[2][0] == '-')
		{
			result = infin_sub(argv[1], &argv[2][1]);
			write(1, result, ft_strlen(result));
			write(1, "\n", 1);
		}
		/* if both are positive */
		else
		{
			result = infin_add(argv[1], argv[2]);
			write(1, result, ft_strlen(result));
			write(1, "\n", 1);
		}
	}
}
