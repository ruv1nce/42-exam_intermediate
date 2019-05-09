#include <stdlib.h>
#include <stdio.h>	// KILLME

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

struct s_node	*nn(int data)
{
	t_node	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

struct s_node	*clone_list(struct s_node *node)
{
	t_node	*dup;
	t_node	*tmp;
	t_node	*new;

	if (!node)
		return (NULL);
	/* Traverse original list, duplicating nodes and inserting them
		between original nodes using ->next. So that orig1->dup1->orig2.
		Point dup->other to symmetric orig nodes (e.g. dup list's
		first node's other will point to orig's first node). */
	dup = nn(node->data);
	dup->other = node;
	tmp = node->next;
	dup->next = node->next;
	node->next = dup;
	while (tmp)
	{
		new = nn(tmp->data);
		new->other = tmp;
		tmp = tmp->next;
		new->next = new->other->next;
		new->other->next = new;
	}
	/* recreate dup's other links */
	tmp = dup;
	while (tmp)
	{
		if (tmp->other->other)
			tmp->other = tmp->other->other->next;
		else
			tmp->other = NULL;
		if (tmp->next)
			tmp = tmp->next->next;
		else
			tmp = NULL;
	}
	/* restore orig's next links */
	tmp = dup;
	while (node)
	{
		if (node->next)
			node->next = node->next->next;
		node = node->next;
		if (tmp->next)
			tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	return (dup);
}

int		main()
{
	t_node	*orig;
	t_node	*dup;
	t_node	*tmp;

	orig = NULL;
	dup = NULL;
	orig = nn(1);
	orig->next = nn(2);
	orig->next->next = nn(3);
	orig->next->next->next = nn(4);
	orig->next->next->next->next = nn(5);
	orig->other = orig->next->next;
	orig->next->other = NULL;
	orig->next->next->other = orig;
	orig->next->next->other = orig;
	orig->next->next->next->other = orig->next->next->next;
	orig->next->next->next->next->other = orig->next;

	printf("original\n");
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

	printf("duplicate\n");
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
