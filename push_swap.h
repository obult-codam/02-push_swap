#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct s_input
{
	struct s_input	*next;
	struct s_input	*prev;
	int		index;
}	t_input;

typedef struct s_indexing
{
	struct s_indexing	*next;
	int			*index;
	int			nbr;
}	t_indexing;

int	ft_index_list(int argc, char **argv, t_input **list, t_indexing **indexing);
t_input	*lstadd_input(t_input *last);
t_indexing	*lstadd_index(t_indexing **lst, int *index, int nbr);
t_indexing	*lstnew_index(t_indexing *next, int *index, int nbr);
t_input	*lstnew_input(t_input *prev);

void	set_index(t_indexing *indexing);

void	write_list_nbr(t_input *last, t_input *write);

#endif