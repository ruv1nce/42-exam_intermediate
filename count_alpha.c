#include <stdio.h>

int        main(int argc, char **argv)
{
	int		i;
	int		j;
	int		occ[26];
	char	let[27];
	int		dp[26];
	int		flag;

	if (argc == 2)
	{
		i = -1;
		/* case when the strings contains all 26 letters */
		let[26] = 0;
		while (++i < 26)
		{
			occ[i] = 0;
			let[i] = 0;
			dp[i] = -1;
		}
		i = -1;
		j = 0;
		while (argv[1][++i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] += 32;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (dp[argv[1][i] - 97] != -1)
					occ[dp[argv[1][i] - 97]]++;
				else
				{
					let[j] = argv[1][i];
					occ[j]++;
					dp[argv[1][i] - 97] = j;
					j++;
				}
			}
		}
		flag = 0;
		i = -1;
		while (let[++i])
		{
			if (!flag)
			{
				printf("%i%c", occ[i], let[i]);
				flag = 1;
			}
			else
				printf(", %i%c", occ[i], let[i]);
		}
	}
	printf("\n");
}

