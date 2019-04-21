#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

typedef struct s_ref
{
	struct s_node	*orig;
	struct s_node	*dup;
}					t_ref;

void			insertion_sort(t_ref *table, int len)
{
	int	i;

	i = 0;
	while (++i < len)
	{
		if (table[i].orig
	}
}

void			add_link(t_node **list, int data)
{
	t_node	*new;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	if (!*list)
		*list = new;
	else
		(*list)->next = new;
}

struct s_node	*clone_list(struct s_node *node)
{
	t_node	*dup;
	t_node	*tmporig;
	t_node	*tmpdup;
	t_ref	*table;
	int		len;
	int		i;

	/* determine list length and allocate ref table*/
	if (!node)
		return (NULL);
	len = 0;
	tmporig = node;
	while (tmporig)
	{
		len++;
		tmporig = tmporig->next;
	}
	if (!(table = malloc(sizeof(*table) * len)))
		return (NULL);
	dup = NULL;
	/* traverse original list, duplicating nodes and ->next links;
	 * store pairs of nodes' addresses (orig + dup) in the ref table */
	/* add first link to the dup list to not lose the head later */
	add_link(&dup, node->data);
	table[0].orig = node;
	table[0].dup = dup;
	tmpdup = dup;
	tmporig = node->next;
	i = 1;
	while (tmporig)
	{
		add_link(&tmpdup, tmporig->data);
		tmpdup = tmpdup->next;
		table[i].orig = tmporig;
		table[i].dup = tmpdup;
		tmporig = tmporig->next;
		i++;
	}
	/* sort ref table by orig list addresses */
	i = -1;
	while (++i < len)
		printf("%p\n", table[i].orig);
	insertion_sort(table, len);
	i = -1;
	while (++i < len)
		printf("%p\n", table[i].orig);
	/* traverse orig list, dereferencing other pointers and searching for
	 * address they point to in ref table; set dup's other pointers to
	 * point to matching dup node address from the ref table */
/*	tmpdup = dup;
	while (node)
	{
		if (node->other)
		{
			i = binsearch(node->other);
			tmpdup->other = table[i].dup;
			node = node->next;
			tmpdup = tmpdup->next;
		}
	}*/
	return (dup);
}

int		main()
{
	t_node	*orig;
	t_node	*dup;
	t_node	*tmp;

	orig = NULL;
	dup = NULL;
	add_link(&orig, 1);
	add_link(&orig->next, 2);
	add_link(&orig->next->next, 3);
	add_link(&orig->next->next->next, 4);
	add_link(&orig->next->next->next->next, 5);
	orig->other = orig->next->next;
	orig->next->other = NULL;
	orig->next->next->other = orig;
	orig->next->next->other = orig;
	orig->next->next->next->other = orig->next->next->next;
	orig->next->next->next->next->other = orig->next;
	tmp = orig;
	while (tmp)
	{
		printf("cur %i ", tmp->data);
		if (tmp->other)
			printf("other %i\n", tmp->other->data);
		else
			printf("other (nil)\n");
		tmp = tmp->next;
	}
	printf("\n");
	dup = clone_list(orig);
	tmp = dup;
	while (tmp)
	{
		printf("cur %i ", tmp->data);
		if (tmp->other)
			printf("other %i\n", tmp->other->data);
		else
			printf("other (nil)\n");
		tmp = tmp->next;
	}
}
