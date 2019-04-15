#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node)
{
	int	seqleft;
	int	seqright;

	if (!node)
		return (0);
	seqleft = 1;
	seqright = 1;
	if (node->left)
	{
		seqleft = longest_sequence(node->left);
		if (node->left->value == (node->value + 1))
			seqleft++;
	}
	if (node->right)
	{
		seqright = longest_sequence(node->right);
		if (node->right->value == (node->value + 1))
			seqright++;
	}
	return (seqleft > seqright ? seqleft : seqright);
}

int	main()
{
	struct s_node	*root;
	root = malloc(sizeof(*root));
	root->value = 10;
	root->left = malloc(sizeof(struct s_node));
	root->left->value = 5;
	root->left->left = malloc(sizeof(struct s_node));
	root->left->left->value = 6;
	root->left->right = malloc(sizeof(struct s_node));
	root->left->right->value = 9;
	root->left->right->left = root->left->right->right = NULL;
	root->left->left->left = malloc(sizeof(struct s_node));
	root->left->left->left->value = 7;
	root->left->left->left->left = root->left->left->left->right = NULL;
	root->left->left->right = malloc(sizeof(struct s_node));
	root->left->left->right->value = 13;
	root->left->left->right->left = root->left->left->right->right = NULL;

//	root->right = NULL;

	root->right = malloc(sizeof(struct s_node));
	root->right->value = 11;
	root->right->left = malloc(sizeof(struct s_node));
	root->right->left->value = 12;
	root->right->right = NULL;
	root->right->left->left = malloc(sizeof(struct s_node));
	root->right->left->left->value = 13;
	root->right->left->right = NULL;
	root->right->left->left->right = malloc(sizeof(struct s_node));
	root->right->left->left->right->value = 14;
	root->right->left->left->left = NULL;
	root->right->left->left->right->left = root->right->left->left->right->right = NULL;

	printf("%i\n", longest_sequence(root));
}
