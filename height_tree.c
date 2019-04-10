struct s_node
{
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int	ht;
	int	httmp;
	int	i;

	ht = 0;
	if (!(root))
		return (0);
	i = -1;
	while (nodes[++i])
	{
		httmp = height_tree(root->nodes[i]);
		ht = (httmp > ht) ? httmp : ht;
	}
	return (ht);
}

int	main()
{
	struct s_node	root;
	struct s_node	rootnodes[4];
	struct s_node	b;
	struct s_node	c;
	struct s_node	aa;
	struct s_node	ab;
	struct s_node	ca;
	struct s_node	cb;
	struct s_node	cba;
	struct s_node	cbb;
	struct s_node	cbaa;

	root->nodes = &rootnodes[0];
	rootnodes[0]->nodes = NULL;
	rootnodes[1]->nodes = NULL;
	rootnodes[]->nodes = NULL;
	rootnodes[1]->nodes = NULL;

}
