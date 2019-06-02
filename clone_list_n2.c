#include <stdlib.h>
// #include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

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
	t_node	*runner;
	int		i;

	/* traverse original list, duplicating nodes and ->next links */
	add_link(&dup, node->data);
	tmpdup = dup;
	tmporig = node->next;
	while (tmporig)
	{
		add_link(&tmpdup, tmporig->data);
		tmpdup = tmpdup->next;
		tmporig = tmporig->next;
	}
	/* traverse original list and for each node check 'other' pointer */
	tmpdup = dup;
	tmporig = node;
	while (tmporig)
	{
		if (tmporig->other)
		{
			/* find how many steps from head is the node pointed by 'other' located */
			i = 0;
			runner = node;
			while (runner != tmporig->other)
			{
				runner = runner->next;
				i++;
			}
			/* replicate the amount of steps for duplicate list */
			runner = dup;
			while (--i >= 0)
				runner = runner->next;
			tmpdup->other = runner;
		}
		tmporig = tmporig->next;
		tmpdup = tmpdup->next;
	}
	return (dup);
}

/*
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
*/
