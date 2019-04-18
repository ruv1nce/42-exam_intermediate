#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void	print_perimeter(struct s_node *root, struct s_node **root_orig, struct s_node **min, struct s_node **max)
{
	if (!root)
		return ;
	if (*min)
	{
		/* print original root */
		if (root == *root_orig)
			printf("%i", root->value);
		/* print nodes on the way to min */
		else
			printf(" %i", root->value);
		if (root == *min)
			*min = NULL;
	}
	/* print all other leafs after min */
	else if (!*min && *max && !root->left && !root->right)
		printf(" %i", root->value);
	print_perimeter(root->left, root_orig, min, max);
	print_perimeter(root->right, root_orig, min, max);
	/* print nodes on the way back from max except original root */
	if (!*max && root != *root_orig)
		printf(" %i", root->value);
	if (root == *max)
		*max = NULL;
}

struct s_node *tree_min(struct s_node *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

struct s_node *tree_max(struct s_node *root)
{
	while (root->right)
		root = root->right;
	return (root);
}

void	perimeter(struct s_node *root)
{
	struct s_node	*min;
	struct s_node	*max;

	if (!root)
		return ;
	min = tree_min(root);
	min = (min == root) ? NULL : min;
	max = tree_max(root);
	max = (max == root) ? NULL : max;
	if (min != max)
		print_perimeter(root, &root, &min, &max);
	printf("\n");
}
