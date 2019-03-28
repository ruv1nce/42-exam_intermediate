#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	void			*content;
	struct s_node	*next;
};

struct s_stack
{
	struct s_node	*top;
};

struct s_stack	*init(void)
{
	struct s_stack	*stack;

	if (!(stack = malloc(sizeof(*stack))))
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void			*pop(struct s_stack *stack)
{
	struct s_node	*tmp;
	void			*content;

	if (!stack)
		return (NULL);
	tmp = stack->top;
	content = tmp->content;
	stack->top = stack->top->next;
	free(tmp);
	return (content);
}

void			push(struct s_stack *stack, void *content)
{
	struct s_node	*new;

	if (!(stack))
		return ;
	if (!(new = malloc(sizeof(*new))))
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void			*peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int				isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

int				main()
{
	char	s1[] = "fuck\n";
	char	s2[] = "off\n";
	struct s_stack	*stack;

	stack = init();
	printf("empty yes %i\n", isEmpty(stack));
	push(stack, s1);
	push(stack, s2);
	printf("s2 %s", peek(stack));
	printf("pop s2 %s", pop(stack));
	printf("empty no %i\n", isEmpty(stack));
	printf("pop s1 %s", pop(stack));
	printf("empty yes %i\n", isEmpty(stack));
}
