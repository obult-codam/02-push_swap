#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	ft_sort_b(t_sort_data data)
{
	if (data.size < 6)
	{
		ft_fast_five_b(data);
		// ft_solve_on_b(data);
	}
	else
	{
		ft_split_in_two(data);
	}
}

void	split_in_groups_b(t_sort_data data)
{
	int	i;
	int	min;

	i = 0;
	min = get_min(data.size, *data.top_b);
	while (i < data.size)
	{
		if ((*data.top_b)->index < (min + data.size / 3))
		{
			ft_rotate(data.top_b, "rb");
		}
		else if ((*data.top_b)->index < (min + (data.size * 2) / 3))
		{
			ft_push(data.top_b, data.top_a, "pa");
			ft_rotate(data.top_a, "ra");
		}
		else
		{
			ft_push(data.top_b, data.top_a, "pa");
		}
		i++;
	}
	ft_bottom_push_bx(data.top_a, data.top_b, ((data.size * 2) / 3) - data.size / 3);
}