struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	descendants(struct s_node *n, int node_count, int *split)
{
	int	desc;

	if (!n)
		return (0);
	desc = 0;
	desc += descendants(n->left, node_count, split);
	desc += descendants(n->right, node_count, split);
	/* second run of function */
	if (!*split && desc + 1 == node_count / 2)
		*split = 1;
	return (desc + 1);

}

int	can_split(struct s_node *n)
{
	/* int split is a boolean indicating whether split is possible */
	int	split;
	int	node_count;

	split = 1;
	node_count = 0;
	/* first run of descendants is just for counting nodes */
	node_count = descendants(n, node_count, &split);
	printf("node count %i\n", node_count);
	split = 0;
	/* second run is for checking for split possibility */
	descendants(n, node_count, &split);
	printf("%i\n", split);
	if (split)
		return (1);
	return (0);
}
