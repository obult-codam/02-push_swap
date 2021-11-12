#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int		index;
}	t_stack;

typedef struct s_indexing
{
	struct s_indexing	*next;
	int			*index;
	int			nbr;
}	t_indexing;


typedef struct s_sort_data
{
	t_stack		**top_a;
	t_stack		**top_b;
	t_stack		*start;
	t_stack		*end;
	int			size;
	int			*min;
	int			*max;
}	t_sort_data;

int	ft_index_list(int argc, char **argv, t_stack **list, t_indexing **indexing);
t_stack	*lstadd_input(t_stack *last);
t_stack	*lstnew_input(t_stack *prev);
t_indexing	*lstadd_index(t_indexing **lst, int *index, int nbr);
t_indexing	*lstnew_index(t_indexing *next, int *index, int nbr);

void	set_index(t_indexing *indexing);

int	nuke_all(t_stack *a_stack, t_stack *b_stack, t_indexing *indexing);

void	write_list_nbr(t_stack *last, t_stack *write);




void	get_minmax(t_sort_data data);

#endif 