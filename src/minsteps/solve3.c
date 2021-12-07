#include "push_swap.h"

void	ft_short_solve(t_sort_data data)
{
	if (data.size == 5)
		min_solve_five(data);
	else if (data.size == 3)
		min_solve_three(data);
	else
		ft_sort(data);
}

void	min_solve_three(t_sort_data data)
{
	int	min;

	min = get_min(3, *data.top_a);
	if ((*data.top_a)->index == (min + 2))
		ft_rotate(data.top_a, "ra");
	else if ((*data.top_a)->next->index == (min + 2))
		ft_rev_rotate(data.top_a, "rra");
	ft_hustle(data);
}

void	min_solve_five(t_sort_data data)
{
	push_first_b(0, 1, data);
	push_first_b(0, 1, data);
	ft_hustle(data);
	min_solve_three(data);
	ft_push_x(data.top_b, data.top_a, "pa", 2);
}

void	push_first_b(int range_start, int range_end, t_sort_data data)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (ft_offset_index(*data.top_a, -1 * i) <= range_end && 
				ft_offset_index(*data.top_a, -1 * i) >= range_start)
		{
			ft_revr_x(data.top_a, "rra", i);
			ft_push(data.top_a, data.top_b, "pb");
			return ;
		}
		else if (ft_offset_index(*data.top_a, i) <= range_end && 
			ft_offset_index(*data.top_a, i) >= range_start)
		{
			ft_rotate_x(data.top_a, "ra", i);
			ft_push(data.top_a, data.top_b, "pb");
			return ;
		}
		i++;
	}
}

int	ft_offset_index(t_stack *start, int offset)
{
	t_stack	*tmp;

	tmp = ft_get_bottom_offset(start, offset * -1);
	return (tmp->index);
}
