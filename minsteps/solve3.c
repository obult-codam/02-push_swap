#include "push_swap.h"

void	min_solve_three(t_sort_data data)
{
	if ((*data.top_a)->index == 2)
		ft_rotate(data.top_a, "ra");
	else if ((*data.top_a)->next->index == 2)
		ft_rev_rotate(data.top_a, "rra");
	ft_solve_2a(data);
}

void	min_solve_five(t_sort_data data)
{
	push_first_b(3, 4, data);
	push_first_b(3, 4, data);
	ft_solve_3a(data);
	ft_push_x(data.top_b, data.top_a, "pa", 2);
	ft_solve_2a(data);
}

void	push_first_b(int range_start, int range_end, t_sort_data data)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (ft_offset_index(*data.top_a, i) <= range_end && 
			ft_offset_index(*data.top_a, i) >= range_start)
		{
			ft_rotate_x(data.top_a, "ra", i);
			ft_push(data.top_a, data.top_b, "pb");
			i = -2;
		}
		else if (ft_offset_index(*data.top_a, -1 * i) <= range_end && 
				ft_offset_index(*data.top_a, -1 * i) >= range_start)
		{
			ft_revr_x(data.top_a, "rra", i);
			ft_push(data.top_a, data.top_b, 'pb');
			i = -2;
		}
		i++;
	}
}

int	ft_offset_index(t_stack *start, int offset)
{
	t_stack	tmp;

	tmp = ft_get_bottom_offset(start, offset * -1);
	return (tmp->index);
}

// move closest 4 or 5 to stack b
// move second closest quickest pos to stack b
// solve 3 on A
// move back both of them from B
// solve 2a