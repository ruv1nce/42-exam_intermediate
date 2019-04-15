#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>	//KILLME

# define VALID(x) (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')
# define UPPER(x) x >= 'A' && x <= 'Z'

typedef struct s_node
{
	int				len;
	char			*s;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

#endif
