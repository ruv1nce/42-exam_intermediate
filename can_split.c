// #include <stdio.h>

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
	// printf("node count %i\n", node_count);
	split = 0;
	/* second run is for checking for split possibility */
	descendants(n, node_count, &split);
	// printf("%i\n", split);
	if (split)
		return (1);
	return (0);
}

/*
void	trav(node *root)
{
	if (root)
	{
		trav(root->left);
		printf("%i\n", root->value);
		trav(root->right);
	}
}

int main()
{
	node	root1 = {
		.value = 28,
		.left = &(node){
			.value = 51,
			.left = &(node){
				.value = 26,
				.left = &(node){.value = 76},
				.right = &(node){.value = 13}
			},
			.right = &(node){.value = 48}
		}
	};

	node	root2 = {
		.value = 28,
		.left = &(node){
			.value = 51,
			.left = &(node){
				.value = 26,
				.left = &(node){.value = 76}
			},
			.right = &(node){.value = 48}
		}
	};

//	trav(&root1);
	printf("split %i\n", can_split(&root1));
//	trav(&root2);
	printf("split %i\n", can_split(&root2));
}
*/
