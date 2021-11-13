#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_sort_parent(t_stack **top_a, int total_nbrs)
{
	t_stack	*b;
	t_sort_data	data;
	
	b = 0;
	data.top_a = top_a;
	data.top_b = &b;
	data.size = total_nbrs;
	ft_sort(data);
}

void	ft_sort(t_sort_data data)
{
	if (data.size < 6)
		return ;
		// ft_solve_on_a(data);
	else
	{
		split_in_groups(data);
		ft_sort_max(data);
		ft_sort_mid(data);
		ft_sort_min(data);
	}
}

void	split_in_groups(t_sort_data data)
{
	int	i;
	int	min;

	i = 0;
	min = get_min(data.size, *data.top_a);
	while (i < data.size)
	{
		if ((*data.top_a)->index < (min + data.size / 3))
		{
			ft_push(data.top_a, data.top_b, "pb");
			ft_rotate(data.top_b, "rb");
		}
		else if ((*data.top_a)->index < (min + (data.size * 2) / 3))
		{
			ft_push(data.top_a, data.top_b, "pb");
		}
		else
		{
			ft_rotate(data.top_a, "ra");
		}
		i++;
	}
	// not always needed how to reduce?
	ft_revr_x(data.top_a, "rra", data.size - (data.size * 2) / 3);
}
