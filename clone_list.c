struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*other;
}					t_node;

struct s_ref
{
	t_node			*orig;
	t_node			*dup;
}					t_ref;

void			add_link(t_node **list, int data)
{
	t_node	*new;

	if (!(new = malloc(sizeof(*new))))
		return ;
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	if (!*list)
		*list = new;
	else
		(*list)->next = new;
}

struct s_node	*clone_list(struct s_node *node)
{
	t_node	*dup;
	t_node	*tmporig;
	t_node	*tmpdup;
	t_ref	*table;
	int		len;
	int		i;

	/* determine list length and allocate ref table*/
	if (!node)
		return (NULL);
	len = 0;
	tmporig = node;
	while (tmporig)
	{
		len++;
		tmporig = tmporig->next;
	}
	if (!(table = malloc(sizeof(*table) * len)))
		return (NULL);
	dup = NULL;
	/* traverse original list, duplicating nodes and ->next links;
	 * store pairs of nodes' addresses (orig + dup) in the ref table */
	/* add first link to the dup list to not lose the head later */
	add_link(&dup, node->data);
	table[0].orig = node;
	table[0].dup = dup;
	tmpdup = dup;
	tmporig = node->next;
	i = 1;
	while (tmporig)
	{
		add_link(&tmpdup, node->data);
		tmpdup = tmpdup->next;
		table[i].orig = tmporig;
		table[i].dup = tmpdup;
		tmporig = tmporig->next;
		i++;
	}
	/* sort ref table by orig list addresses */
	quicksort(table, len);
	/* traverse orig list, dereferencing other pointers and searching for
	 * address they point to in ref table; set dup's other pointers to
	 * point to matching dup node address from the ref table */
	tmpdup = dup;
	while (node)
	{
		if (node->other)
		{
			i = binsearch(node->other);
			tmpdup->other = table[i].dup;
			node = node->next;
			tmpdup = tmpdup->next;
		}
	}
	return (dup);
}
