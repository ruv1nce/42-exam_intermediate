#include "ord_alphlong.h"

void	print_word(char	*w, int len)
{
	static int	prev_len;

	if (prev_len)
	{
		if (prev_len == len)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
		write(1, w, len);
		prev_len = len;
}

void	in_trav(t_node *root)
{
	if (root)
	{
		in_trav(root->left);
		print_word(root->s, root->len);
		in_trav(root->right);
	}
}

int		ft_strcmp_ignore_case(char *w, char *s)
{
	char	a;
	char	b;

	while (*w && *s)
	{
		if (UPPER(*w))
			a = *w + 32;
		else
			a = *w;
		if (UPPER(*s))
			b = *s + 32;
		else
			b = *s;
		if (a != b)
			break ;
		w++;
		s++;
	}
	return (a - b);
}

int		ft_strlen(char *w)
{
	int	len;

	len = 0;
	while (*w)
	{
		len++;
		w++;
	}
	return (len);
}

void	save_word(t_node **root, char *w, int len)
{
	t_node	*new;
	t_node	*spot;
	t_node	*prev;
	int		cmp;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->len = len;
	new->s = w;
	new->left = NULL;
	new->right = NULL;
	if (!*root)
		*root = new;
	else
	{
		spot = *root;
		while (spot)
		{
			prev = spot;
			if (len < spot->len)
				spot = spot->left;
			else if (len > spot->len)
				spot = spot->right;
			/* if lengths are equal, compare strings */
			else
			{
				cmp = ft_strcmp_ignore_case(w, spot->s);
				if (cmp < 0)
					spot = spot->left;
				else
					spot = spot->right;
			}
		}
		if (len < prev->len || (len == prev->len && cmp < 0))
			prev->left = new;
		else
			prev->right = new;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag;
	char	*word;
	t_node	*root;

	if (argc == 2)
	{
		flag = 1;
		root = NULL;
		i = -1;
		while (argv[1][++i])
		{
			if (VALID(argv[1][i]))
			{
				if (flag)
				{
					word = &argv[1][i];
					flag = 0;
				}
			}
			else
			{
				if (!flag)
				{
					argv[1][i] = 0;
					save_word(&root, word, ft_strlen(word));
					flag = 1;
				}
			}
		}
		if (!argv[1][i] && !flag)
			save_word(&root, word, ft_strlen(word));
		in_trav(root);
	}
	write(1, "\n", 1);
}
