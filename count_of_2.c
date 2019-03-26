#include <stdio.h>

int	count_of_2(int n)
{
	int	count;
	/* decimal coeffecient for iteration */
	int	coeff;
	/* previous digit */
	int	prev;

	count = 0;
	coeff = 1;
	prev = 0;
	while (n)
	{
		if (n % 10 > 2)
			count += (n / 10 + 1) * coeff;
		else if (n % 10 == 2)
			count += prev + 1;
		else
			count += (n / 10) * coeff;
		prev = n % 10;
		n /= 10;
		coeff *= 10;
	}
	return (count);
}

int	main()
{
	printf("  0:  0? %3i\n", count_of_2(0));
	printf("  2:  1? %3i\n", count_of_2(2));
	printf(" 11:  1? %3i\n", count_of_2(11));
	printf(" 25:  9? %3i\n", count_of_2(25));
	printf(" 35: 14? %3i\n", count_of_2(35));
	printf("100: 14? %3i\n", count_of_2(100));
	printf("2115231569: ? %3i\n", count_of_2(2115231569));
	printf("33:     %3i\n", count_of_2(33));
	printf("333:    %3i\n", count_of_2(333));
	printf("3333:   %3i\n", count_of_2(3333));
	printf("33333:  %3i\n", count_of_2(33333));
	printf("333333: %3i\n", count_of_2(333333));
	printf("11:     %1i\n", count_of_2(11));
	printf("111:    %1i\n", count_of_2(111));
	printf("1111:   %1i\n", count_of_2(1111));
	printf("11111:  %1i\n", count_of_2(11111));
	printf("111111: %1i\n", count_of_2(111111));
}
