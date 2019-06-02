// #include <stdio.h>
// #include <stdlib.h>

struct s_node
{
	int 			value;
	struct s_node	*left;
	struct s_node	*right;
};

void	in_trav(struct s_node *root)
{
	if (root)
	{
		in_trav(root->left);
		printf("%i ", root->value);
		in_trav(root->right);
	}
}

void	reverse_tree(struct s_node *root)
{
	struct s_node	*tmp;

	if (root)
	{
		reverse_tree(root->left);
		reverse_tree(root->right);
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

/*
int	main()
{
	struct s_node	*root;
	root = malloc(sizeof(*root));
	root->value = 10;
	root->left = malloc(sizeof(struct s_node));
	root->left->value = 6;
	root->left->left = malloc(sizeof(struct s_node));
	root->left->left->value = 3;
	root->left->right = malloc(sizeof(struct s_node));
	root->left->right->value = 7;
	root->left->right->left = root->left->right->right = NULL;
	root->left->left->left = malloc(sizeof(struct s_node));
	root->left->left->left->value = 1;
	root->left->left->left->left = root->left->left->left->right = NULL;
	root->left->left->right = malloc(sizeof(struct s_node));
	root->left->left->right->value = 4;
	root->left->left->right->left = root->left->left->right->right = NULL;
	root->right = malloc(sizeof(struct s_node));
	root->right->value = 20;
	root->right->left = malloc(sizeof(struct s_node));
	root->right->left->value = 15;
	root->right->right = NULL;
	root->right->left->left = malloc(sizeof(struct s_node));
	root->right->left->left->value = 13;
	root->right->left->right = NULL;
	root->right->left->left->right = malloc(sizeof(struct s_node));
	root->right->left->left->right->value = 14;
	root->right->left->left->left = NULL;
	root->right->left->left->right->left = root->right->left->left->right->right = NULL;

	in_trav(root);
	printf("\n");
	reverse_tree(root);
	in_trav(root);
	printf("\n");
}
*/
