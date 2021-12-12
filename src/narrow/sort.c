#include "libft.h"
#include "push_swap.h"

void	ft_sort_parent(t_stack **top_a, int total_nbrs)
{
	t_stack		*b;
	t_sort_data	data;

	b = 0;
	data.top_a = top_a;
	data.top_b = &b;
	data.size = total_nbrs;
	if (total_nbrs <= 5)
		ft_short_solve(data);
	else
		ft_sort(data);
}

void	ft_sort(t_sort_data data)
{
	if (data.size < 6)
		ft_solve_on_a(data);
	else if (data.size <= 12)
	{
		ft_medium_size_a(data);
	}
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
	int	p;
	int	min;

	i = 0;
	p = 0;
	if (data.size % 3)
		p = 1;
	min = get_min(data.size, *data.top_a);
	while (i < data.size)
	{
		if ((*data.top_a)->index < (min + data.size / 3))
		{
			ft_push(data.top_a, data.top_b, "pb");
			ft_rotate(data.top_b, "rb");
		}
		else if ((*data.top_a)->index < (min + data.size / 3 * 2 + p))
		{
			ft_push(data.top_a, data.top_b, "pb");
		}
		else
		{
			ft_rotate(data.top_a, "ra");
		}
		i++;
	}
	ft_revr_x(data.top_a, "rra", data.size / 3 + data.size % 3 / 2);
}
