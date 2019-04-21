#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

void			add_link(t_node **list)
{
	t_node	*new;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
		(*list)->next = new;
}

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	t_node	*uno;
	t_node	*dos;

	uno = lst1;
	while (uno)
	{
		dos = lst2;
		while (dos)
		{
			if (dos == uno)
				return (dos);
			dos = dos->next;
		}
		uno = uno->next;
	}
	return (NULL);
}

int		main()
{
	t_node	*one;
	t_node	*two;
	t_node	*tmp;

	one = NULL;
	two = NULL;
	add_link(&one);
	add_link(&one->next);
	add_link(&one->next->next);
	add_link(&one->next->next->next);
	add_link(&one->next->next->next->next);
	add_link(&two);
	add_link(&two->next);
	add_link(&two->next->next);
	two->next->next->next = one->next->next;

	tmp = one;
	printf("one\n");
	while (tmp)
	{
		printf("%p\n", tmp);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = two;
	printf("two\n");
	while (tmp)
	{
		printf("%p\n", tmp);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = intersection(one, two);
	printf("inter %p\n", tmp);
}
