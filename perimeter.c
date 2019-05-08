#include <stdio.h>

typedef struct		s_node
{
	int				value;
	struct s_node	*right;
	struct s_node	*left;
}					t_node;

void	print_left(struct s_node *root)
{
	if (root->left || root->right)
		printf(" %i", root->value);
	if (root->left)
		print_left(root->left);
}

void	print_leafs(struct s_node *root)
{
	if (root->left)
		print_leafs(root->left);
	if (root->right)
		print_leafs(root->right);
	if (!root->left && !root->right)
		printf(" %i", root->value);
}

void	print_right(struct s_node *root)
{
	if (root->right)
		print_right(root->right);
	if (root->right || root->left)
		printf(" %i", root->value);
}

void	perimeter(struct s_node *root)
{
	if (!root)
		return;
	/* print original root */
	printf("%i", root->value);
	if (root->left)
	{
		print_left(root->left);
		print_leafs(root->left);
	}
	if (root->right)
	{
		print_leafs(root->right);
		print_right(root->right);
	}
	printf("\n");
}

int		main()
{
	t_node small = {
		.value = 49,
		.right = &(t_node){
			.value = 58,
			.right = &(t_node){.value = 44}
		}
	};
	perimeter(&small);
	printf("\n");

	t_node small2 = {
		.value = 49,
		.right = &(t_node){
			.value = 58,
			.left = &(t_node){.value = 44}
		}
	};
	perimeter(&small2);
	printf("\n");

	t_node small3 = {
		.value = 49,
		.left = &(t_node){
			.value = 58,
			.right = &(t_node){.value = 44}
		}
	};
	perimeter(&small3);
	printf("\n");

	t_node small4 = {
		.value = 49,
		.left = &(t_node){
			.value = 58,
			.left = &(t_node){.value = 44}
		}
	};
	perimeter(&small4);
	printf("\n");

	t_node root = {
		.value = 92,
		.left = &(t_node){
			.value = 85,
			.left = &(t_node){
				.value = 79,
				.right = &(t_node){
					.value = 10,
					.left = &(t_node){
						.value = 39,
						.left = &(t_node){
							.value = 35,
							.left = &(t_node){.value = 96}
						}
					}
				}
			}
		},
		.right = &(t_node){
			.value = 26,
			.right = &(t_node){
				.value = 64,
				.left = &(t_node){
					.value = 40,
					.left = &(t_node){
						.value = 88,
						.left = &(t_node){
							.value = 12,
							.left = &(t_node){.value = 58}
						},
						.right = &(t_node){
							.value = 55,
							.left = &(t_node){.value = 58},
							.right = &(t_node){.value = 41}
						}
					},
					.right = &(t_node){
						.value = 10,
						.left = &(t_node){
							.value = 52,
							.left = &(t_node){.value = 22},
							.right = &(t_node){.value = 35}
						},
						.right = &(t_node){
							.value = 87,
							.right = &(t_node){.value = 31}
						}
					}
				},
				.right = &(t_node){
					.value = 78,
					.left = &(t_node){
						.value = 2,
						.left = &(t_node){
							.value = 33,
							.right = &(t_node){.value = 55}
						},
						.right = &(t_node){
							.value = 11,
							.left = &(t_node){.value = 99}
						}
					},
					.right = &(t_node){
						.value = 85,
						.right = &(t_node){.value = 51}
					}
				}
			}
		}
	};
	perimeter(&root);
	printf("\n");
}
