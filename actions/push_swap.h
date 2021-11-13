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
	int			size;
}	t_sort_data;

int	ft_index_list(int argc, char **argv, t_stack **list, t_indexing **indexing);
t_stack	*lstadd_input(t_stack *last);
t_stack	*lstnew_input(t_stack *prev);
t_indexing	*lstadd_index(t_indexing **lst, int *index, int nbr);
t_indexing	*lstnew_index(t_indexing *next, int *index, int nbr);

void	set_index(t_indexing *indexing);

int	nuke_all(t_stack *a_stack, t_stack *b_stack, t_indexing *indexing);

void	write_list_nbr(t_stack *last, t_stack *write);


void	ft_sort_parent(t_stack **top_a, int total_nbrs);
void	ft_sort(t_sort_data data);
void	split_in_groups(t_sort_data data);
void	ft_sort_b(t_sort_data data);
void	split_in_groups_b(t_sort_data data);

void	ft_sort_min(t_sort_data data);
void	ft_sort_mid(t_sort_data data);
void	ft_sort_max(t_sort_data data);
int	get_min(int size, t_stack *start);
t_stack		*ft_get_bottom_offset(t_stack *start, int offset);

void	ft_push(t_stack **origin, t_stack **dest, char *msg);
void	ft_bottom_push(t_stack **org, t_stack **dst, char from);
void	ft_bottom_push_x(t_stack **org, t_stack **dst, char from, int x);

void	ft_rotate(t_stack **r, char *msg);
void	ft_rev_rotate(t_stack **r, char *msg);
void	ft_revr_x(t_stack **r, char *msg, int rotations);

#endif 