#include "push_swap.h"
#include "libft.h"

void	ft_sort_min(t_sort_data data)
{
	data.size = data.size / 3;
	data.start = ft_get_bottom_offset(*data.top_b, data.size);
	ft_revr_x(data.top_b, "rrb", data.size);
	ft_sort_b(data);
}

void	ft_sort_mid(t_sort_data data)
{
	data.size = data.size - (data.size - data.size / 3);
	data.start = *data.top_b;
	ft_sort_b(data);
}

void	ft_sort_max(t_sort_data data)
{
	data.size = data.size - (data.size * 2 / 3);
	data.start = *data.top_a;
	ft_sort(data);
}

int	get_min(int size, t_stack *start)
{
	int	i;
	int	min;

	i = 0;
	min = start->index;
	while (i < size)
	{
		if (start->index < min)
			min = start->index;
		i++;
		start = start->next;
	}
	return (min);
}

t_stack		*ft_get_bottom_offset(t_stack *start, int offset)
{
	int	i;

	i = 0;
	while (i < offset)
	{
		start = start->prev;
		i++;
	}
	return (start);
}