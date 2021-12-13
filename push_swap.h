/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:32:28 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:34:29 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}	t_stack;

typedef struct s_indexing
{
	struct s_indexing	*next;
	int					*index;
	int					nbr;
}	t_indexing;

typedef struct s_sort_data
{
	t_stack		**top_a;
	t_stack		**top_b;
	int			size;
}	t_sort_data;

int			ft_index_list(int argc, char **argv, t_stack **list,
				t_indexing **indexing);
t_stack		*lstadd_input(t_stack *last);
t_stack		*lstnew_input(t_stack *prev);
t_indexing	*lstadd_index(t_indexing **lst, int *index, int nbr);
t_indexing	*lstnew_index(t_indexing *next, int *index, int nbr);

t_stack		*ft_add_to_lst(int argc, char **argv, t_stack **list,
				t_indexing **idx);

void		set_index(t_indexing *indexing);

int			nuke_all(t_stack *a_stack, t_stack *b_stack, t_indexing *indexing);

void		write_list_nbr(t_stack *write, t_stack *last);

void		ft_sort_parent(t_stack **top_a, int total_nbrs);
void		ft_sort(t_sort_data data);
void		split_in_groups(t_sort_data data);
void		ft_sort_b(t_sort_data data);
void		split_in_groups_b(t_sort_data data);

void		ft_sort_min(t_sort_data data);
void		ft_sort_mid(t_sort_data data);
void		ft_sort_max(t_sort_data data);
int			get_min(int size, t_stack *start);
t_stack		*ft_get_bottom_offset(t_stack *start, int offset);

void		ft_push(t_stack **origin, t_stack **dest, char *msg);
void		ft_push_x(t_stack **org, t_stack **dst, char *msg, int x);
void		ft_bottom_push_a(t_stack **org, t_stack **dst);
void		ft_bottom_push_ax(t_stack **org, t_stack **dst, int x);
void		ft_bottom_push_bx(t_stack **org, t_stack **dst, int x);

void		ft_rotate(t_stack **r, char *msg);
void		ft_rotate_x(t_stack **r, char *msg, int rotations);
void		ft_rev_rotate(t_stack **r, char *msg);
void		ft_revr_x(t_stack **r, char *msg, int rotations);

void		ft_swap(t_stack *swap);
void		ft_swap_a(t_stack *swap);
void		ft_swap_b(t_stack *swap);
void		ft_swapsort(t_sort_data data);
void		ft_swapsolve(t_sort_data data);

void		ft_solve_on_a(t_sort_data data);
void		ft_solve_2a(t_sort_data data);
void		ft_solve_3a(t_sort_data data);
void		ft_solve_4a(t_sort_data data);
void		ft_solve_5a(t_sort_data data);

void		ft_hustle(t_sort_data data);
int			ft_quicksolve(t_sort_data data);
void		ft_solve_on_b(t_sort_data data);

int			is_sorted(int argc, char **argv);

void		ft_short_solve(t_sort_data data);
void		min_solve_three(t_sort_data data);
void		min_solve_five(t_sort_data data);
void		push_first_b(int range_start, int range_end, t_sort_data data);
int			ft_offset_index(t_stack *start, int offset);

void		ft_split_in_two(t_sort_data data);
void		ft_medium_size_a(t_sort_data data);

void		ft_fast_five_b(t_sort_data data);

int			fo_atoi(const char *nptr, int *error);

#endif