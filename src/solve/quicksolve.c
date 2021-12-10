#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h> 

void	ft_hustle(t_sort_data data)
{
	if (*data.top_b == NULL)
		ft_solve_2a(data);
	else if ((*data.top_a)->index > (*data.top_a)->next->index)
	{
		if ((*data.top_b)->index < (*data.top_b)->next->index)
		{
			ft_swap(*data.top_a);
			ft_swap(*data.top_b);
			ft_putendl_fd("ss", 1);
		}
		else
			ft_swap_a(*data.top_a);
	}
	else if ((*data.top_b)->index < (*data.top_b)->next->index)
	{
		ft_swap_b(*data.top_b);
	}
}

int	ft_send_2ba(t_sort_data data)
{
	int	i;
	int	r;
	int	max;

	i = 0;
	r = 0;
	max = data.size + get_min(data.size, *data.top_b) - 1;
	while (i < data.size)
	{
		if (i - r == 2)
			break ;
		if ((*data.top_b)->index >= max -1)
		{
			ft_push(data.top_b, data.top_a, "pa");
			ft_hustle(data);
		}
		else
		{
			ft_rotate(data.top_b, "rb");
			r++;
		}
		i++;
	}
	return (r);
}

void	ft_solve_on_b(t_sort_data data)
{
	int	r;
	
	while (data.size)
	{
		if (data.size > 1)
		{
			r = ft_send_2ba(data);
			ft_revr_x(data.top_b, "rrb", r);
			data.size = data.size - 2;
		}
		else if (data.size == 1)
		{
			ft_push(data.top_b, data.top_a, "pa");
			data.size--;
		}
	}
}

int		push_one_a(int range_start, int range_end, t_sort_data data)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (ft_offset_index(*data.top_b, -1 * i) <= range_end && 
				ft_offset_index(*data.top_b, -1 * i) >= range_start)
		{
			ft_revr_x(data.top_b, "rrb", i);
			ft_push(data.top_b, data.top_a, "pa");
			if ((*data.top_a)->index == range_end)
				return (1);
			return (0);
		}
		else if (ft_offset_index(*data.top_b, i) <= range_end && 
			ft_offset_index(*data.top_b, i) >= range_start)
		{
			ft_rotate_x(data.top_b, "rb", i);
			ft_push(data.top_b, data.top_a, "pa");
			if ((*data.top_a)->index == range_end)
				return (1);
			return (0);
		}
		i++;
	}
}

void	ft_fast_five_b (t_sort_data data)
{
	if (push_one_a(4, 5, data)) // 4 and five are placeholders need to use get_min to calc them!
}