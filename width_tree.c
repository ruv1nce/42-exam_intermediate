struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

static int	width;

int	height_tree(struct s_node *n)
{
	int			htleft;
	int			htright;

	if (!n)
		return (0);
	htleft = height_tree(n->left);
	htright = height_tree(n->right);
	if (htleft + htright + 1 > width)
		width = htleft + htright + 1;
	return (htleft > htright ? htleft + 1 : htright + 1);
}

int	width_tree(struct s_node *n)
{
	width = 0;
	height_tree(n);
	return (width);
}
