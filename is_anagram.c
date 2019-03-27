#include <stdio.h>

int	is_anagram(char *a, char *b)
{
	char *bstart;

	bstart = b;
	while (*b)
		b++;
	b--;
	while (*a && b >= bstart)
	{
		if (*a != *b)
			return (0);
		a++;
		b--;
	}
	if (*a || ++b != bstart)
	   return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%i\n", is_anagram(argv[1], argv[2]));
}
