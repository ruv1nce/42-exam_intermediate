#include <string.h>

#define ADD(x) ((x - '0') % 2 == 0 ? 1 : -1)

char	*longest_subarray(char *arr)
{
	int i, j, start, sum = 0, maxlen = 0, len = strlen(arr);
	char *s;

	/* increment starting index in outer loop */
	for (i = 0; i < len; i++)
	{
		sum = ADD(arr[i]);
		/* try all possible subarrays starting with current i index */
		for (j = i + 1; j < len; j++)
		{
			sum += ADD(arr[j]);
			/* update maxlen and starting index if longer valid subarray found */
			if (!sum && maxlen < j - i + 1)
			{
				maxlen = j - i + 1;
				start = i;
			}
		}
	}
	s = malloc(maxlen + 1);
	s[maxlen] = 0;
	for (i = start, j = 0; j < maxlen; i++, j++)
		s[j] = arr[i];
	return (s);
}
