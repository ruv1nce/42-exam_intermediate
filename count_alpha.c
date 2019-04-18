#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned char	let[27];
	int				occ[26];
	unsigned char	*s;
	int				i;
	int				j;

	if (argc == 2)
	{
		s = (unsigned char *)*(argv + 1);
		i = -1;
		while (++i < 27)
			let[i] = 0;
		i = -1;
		while (++i < 26)
			occ[i] = 0;
		i = -1;
		j = 0;
		while (s[++i])
		{
			/* uppercase to lower */
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				/* if it's a first occurrence, add letter to let array */
				if (!occ[s[i] - 97])
				{
					let[j] = s[i];
					j++;
				}
				/* increment the corresponding occurrence cell */
				occ[s[i] - 97]++;
			}
		}
		i = -1;
		j = 1;
		while (let[++i])
		{
			if (j)
			{
				printf("%i%c", occ[let[i] - 97], let[i]);
				j = 0;
			}
			else
				printf(", %i%c", occ[let[i] - 97], let[i]);
		}
	}
	printf("\n");
}

