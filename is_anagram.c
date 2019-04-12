#include <stdio.h>

int	is_anagram(char *a, char *b)
{
	int				*sym[127];
	int				i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)a;
	y = (unsigned char *)b;
	i = 31;
	while (++i < 127)
		sym[i] = 0;
	i = -1;
	while (x[++i])
		sym[x[i]]++;
	i = -1;
	while (y[++i])
		sym[y[i]]--;
	i = 31;
	while (++i < 127)
		if (sym[i])
			return (0);
	return (1);
}

int	main(int argc, char ** argv)
{
	if (argc > 1)
		printf("%i\n", is_anagram(argv[1], argv[2]));
}
