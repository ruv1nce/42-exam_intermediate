// #include <stdio.h>

int	count_of_2(int n)
{
	int	count;
	/* decimal coeffecient for iteration */
	int	coeff;
	int	n_orig;

	count = 0;
	coeff = 1;
	n_orig = n;
	/* count, how many times 2 is found in each position, starting from rightmost */
	while (n)
	{
		/* for n_orig=125 and n=125 '2' in 3rd position will be found (125/10+1)*1 = 13 times */
		if (n % 10 > 2)
			count += (n / 10 + 1) * coeff;
		/* for n_orig=125 and n=12, '2' in 2nd position will be found 12/10*10 + 125-12*10+1 = 16 times */
		else if (n % 10 == 2)
			count += (n / 10) * coeff + (n_orig - n * coeff + 1);
		/* for n_orig=125 and n=1, '2' in 1st position will be found 1/10*10 = 0 times */
		else
			count += (n / 10) * coeff;
		n /= 10;
		coeff *= 10;
	}
	return (count);
}

/*
int	main()
{
	printf("%1i\n", count_of_2(125));
}
*/
