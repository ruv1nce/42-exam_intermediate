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

void			insertion_sort(t_ref *table, int len, int mode)
{
	int	i;
	int	j;
	struct s_node	*tmporig;
	struct s_node	*tmpdup;

	i = 0;
	while (++i < len)
	{
		if (!mode)
		{
			if (table[i].orig < table[i - 1].orig)
			{
				tmporig = table[i].orig;
				tmpdup = table[i].dup;
				j = i;
				while (--j >= 0 && tmporig < table[j].orig)
				{
					table[j + 1].orig = table[j].orig;
					table[j + 1].dup = table[j].dup;
				}
				table[++j].orig = tmporig;
				table[j].dup = tmpdup;
			}
		}
		else
		{
			if (table[i].orig > table[i - 1].orig)
			{
				tmporig = table[i].orig;
				tmpdup = table[i].dup;
				j = i;
				while (--j >= 0 && tmporig > table[j].orig)
				{
					table[j + 1].orig = table[j].orig;
					table[j + 1].dup = table[j].dup;
				}
				table[++j].orig = tmporig;
				table[j].dup = tmpdup;
			}
		}
	}
}

int			binsearch(t_ref *table, int len, t_node *node, int sort)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = len - 1;
	while (i <= j)
	{
		k = (i + j) / 2;
		if (table[k].orig == node)
			return (k);
		else if ((!sort && table[k].orig > node) || (sort && table[k].orig < node))
			j = k - 1;
		else
			i = k + 1;
	}
	return (-1);
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
	int		sort;
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
	/* check the current sorting direction of addresses: if the list was
	 * created by adding nodes to the tail of the list, it will be in
	 * ascending order; if it was created by push_front, - descending */
	if (table[0].orig < table[len - 1].orig)
		sort = 0;
	else
		sort = 1;
	/* sort ref table by orig list addresses (most probably, it's
	 * already sorted, so insertion sort is the method of choice) */
	insertion_sort(table, len, sort);
	/* traverse orig list, dereferencing other pointers and searching for
	 * address they point to in ref table; set dup's other pointers to
	 * point to matching dup node address from the ref table */
	tmpdup = dup;
	while (node)
	{
		if (node->other)
		{
			i = binsearch(table, len, node->other, sort);
			tmpdup->other = table[i].dup;
		}
		node = node->next;
		tmpdup = tmpdup->next;
	}
	return (dup);
}

int		main()
{
	t_node	*orig;
	/* orig2 is needed to make sure that sorting works */
	t_node	*orig2;
	t_node	*dup;
	t_node	*tmp;

	orig = NULL;
	dup = NULL;
	add_link(&orig, 1);
	add_link(&orig2, 4);
	add_link(&orig->next, 2);
	add_link(&orig->next->next, 3);
	orig->next->next->next = orig2;
	add_link(&orig->next->next->next->next, 5);
	orig->other = orig->next->next;
	orig->next->other = NULL;
	orig->next->next->other = orig;
	orig->next->next->other = orig;
	orig->next->next->next->other = orig->next->next->next;
	orig->next->next->next->next->other = orig->next;
	tmp = orig;
	printf("original\n");
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
	printf("duplicate\n");
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
