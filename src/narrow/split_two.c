#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	ft_split_in_two(t_sort_data data)
{
	int	i;
	int	min;
	int	size;

	i = 0;
	size = data.size;
	min = get_min(data.size, *data.top_b);
	while (i < data.size)
	{
		if ((*data.top_b)->index < (min + (data.size / 2)))
		{
			ft_rotate(data.top_b, "rb");
		}
		else
		{
			ft_push(data.top_b, data.top_a, "pa");
		}
		i++;
	}
	ft_revr_x(data.top_b, "rrb", data.size / 2);
	data.size = (size - (size / 2));
	ft_sort(data);
	data.size = (size / 2);
	ft_sort_b(data);
}

void	ft_medium_size_a(t_sort_data data)
{
	int	i;
	int	min;
	int	size;

	i = 0;
	size = data.size;
	min = get_min(data.size, *data.top_a);
	while (i < data.size)
	{
		if ((*data.top_a)->index < (min + data.size / 2))
		{
			ft_push(data.top_a, data.top_b, "pb");
		}
		else
		{
			ft_rotate(data.top_a, "ra");
		}
		i++;
	}
	ft_revr_x(data.top_a, "rra", size - (size / 2));
	data.size = size - (size / 2);
	ft_sort(data);
	data.size = size / 2;
	ft_sort_b(data);
}