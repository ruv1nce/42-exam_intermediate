#include <stdio.h>

typedef struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
} t_node;

void print_perimeter(struct s_node *root, struct s_node **root_orig, struct s_node **min, struct s_node **max)
{
	if (!root)
		return;
	if (*min)
	{
		/* print nodes on the way to min */
		if (root != *root_orig)
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

void perimeter(struct s_node *root)
{
	struct s_node *min;
	struct s_node *max;

	if (!root)
		return;
	/* print original root */
	printf("%i", root->value);
	min = tree_min(root);
	max = tree_max(root);
	min = (min == root) ? NULL : min;
	max = (max == root) ? NULL : max;
	if (min != max)
		print_perimeter(root, &root, &min, &max);
	printf("\n");
}

int main()
{
	t_node small = {
		.value = 49,
		.right = &(t_node){
			.value = 58,
			.right = &(t_node){.value = 44}
		}
	};

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
	perimeter(&small);
}
