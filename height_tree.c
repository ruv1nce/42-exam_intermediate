#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int           value;
	struct s_node **nodes;
};

struct s_node	*create_node(int val)
{
	struct s_node	*new;
	int				i;

	new = malloc(sizeof(*new));
	new->value = val;
	new->nodes = malloc(sizeof(*new->nodes) * 4);
	i = -1;
	while (++i < 4)
		new->nodes[i] = NULL;
	return (new);
}

int height_tree(struct s_node *root)
{
	int	ht;
	int	httmp;
	int	i;

	/* initialize height as 0 in each call of the recursion */
	ht = 0;
	if (!(root))
		return (-1);
	i = 0;
	/* height will be incremented on all levels except lowest one.
	 * this way we will discount 1 ht, because edges = (levels - 1) */
	if (root->nodes)
	{
		while (root->nodes[i])
		{
			/* store the return of the recursion in httmp.
			 * only overwrite ht if the result is bigger */
			httmp = 1 + height_tree(root->nodes[i]);
			ht = (httmp > ht) ? httmp : ht;
			i++;
		}
	}
	return (ht);
}

int	main()
{
	struct s_node	*root;
	int				i;
	int				val;

	root = create_node(1);
	val = 2;
	i = -1;
	while (++i < 3)
	{
		root->nodes[i] = create_node(val);
		val++;
	}
	root->nodes[0]->nodes[0] = create_node(10);
	root->nodes[1]->nodes[0] = create_node(20);
	root->nodes[1]->nodes[0]->nodes[0] = create_node(30);

	printf("%i\n", height_tree(root));
}
