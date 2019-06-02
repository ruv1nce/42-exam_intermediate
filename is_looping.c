// #include <stdlib.h>
// #include <stdio.h>

struct s_node
{
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node	*runner;

	runner = node;
	while (node && runner)
	{
		node = node->next;
		runner = runner->next;
		if (runner)
			runner = runner->next;
		if (node && runner && node == runner)
			return (1);
	}
	return (0);
}

struct s_node	*newnode()
{
	struct s_node	*new;

	new = malloc(sizeof(*new));
	new->next = 0;
	return (new);
}

/*
int	main()
{
	struct s_node	*a;
	struct s_node	*b;

	a = newnode();
	a->next = newnode();
	a->next->next = newnode();
	a->next->next->next = newnode();
	a->next->next->next->next = a->next;
	printf("%i\n", is_looping(a));

	b = newnode();
	a->next = newnode();
	a->next->next = newnode();
	a->next->next->next = newnode();
	a->next->next->next->next = newnode();
	printf("%i\n", is_looping(b));
}
*/
