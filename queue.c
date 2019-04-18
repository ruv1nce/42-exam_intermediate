#include <stdlib.h>
#include <stdio.h> // KILLME

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue	*init(void)
{
	struct s_queue *q;

	if (!(q = malloc(sizeof(*q))))
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node        *new;

	if (queue)
	{
		if (!(new = malloc(sizeof(*new))))
			return ;
		new->content = content;
		new->next = NULL;
		if (!queue->first)
			queue->first = new;
		else
			queue->last->next = new;
		queue->last = new;
	}
}

void	*dequeue(struct s_queue *queue)
{
	struct s_node        *tmp;
	void                        *ret;

	ret = NULL;
	if (queue && queue->first)
	{
		if (queue->first == queue->last)
			queue->last = NULL;
		tmp = queue->first;
		ret = tmp->content;
		queue->first = tmp->next;
		free(tmp);
	}
	return (ret);
}

void	*peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->content);
}

int		isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

int		main()
{
	char        s1[] = "fuck\n";
	char        s2[] = "off\n";
	struct s_queue        *q;

	q = init();
	printf("peek %s\n", peek(q));
	printf("empty yes %i\n", isEmpty(q));
	enqueue(q, s1);
	enqueue(q, s2);
	printf("s1 %s", q->first->content);
	printf("s2 %s", q->last->content);
	printf("deq s1 %s", dequeue(q));
	printf("empty no %i\n", isEmpty(q));
	printf("peek s2 %s", peek(q));
	printf("deq s2 %s", dequeue(q));
	printf("deq nothing %s", dequeue(q));
}
