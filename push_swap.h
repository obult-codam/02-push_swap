#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct s_input
{
	t_input	*next;
	t_input	*prev;
	int		index;
}	t_input;

typedef struct s_indexing
{
	t_indexing	*next;
	int			*index;
	int			nbr;
}	t_indexing;

#endif