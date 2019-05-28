struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node	*bst_min(struct s_node *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

struct s_node	*bst_max(struct s_node *root)
{
	while (root->right)
		root = root->right;
	return (root);
}

void			in_trav(struct s_node *root, struct s_node *min, struct s_node *max)
{
	static struct s_node	*prev;

	if (root)
	{
		/* prevent from traversing left from min (it points to max) */
		if (root != min)
			in_trav(root->left, min, max);
		/* update links for all nodes except min (for min prev == 0 ) */
		if (prev)
		{
			prev->right = root;
			root->left = prev;
		}
		/* set prev to current node */
		prev = root;
		/* prevent from traversing right from max (it points to min) */
		if (root != max)
			in_trav(root->right, min, max);
	}
}	

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*min;
	struct s_node	*max;

	if (!bst)
		return (bst);
	min = bst_min(bst);
	max = bst_max(bst);
	min->left = max;
	max->right = min;
	in_trav(bst, min, max);
	return (min);
}
