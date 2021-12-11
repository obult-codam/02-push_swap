#include "push_swap.h"
#include <unistd.h>

void	ft_solve_on_a(t_sort_data data)
{
	if (data.size == 1)
		return ;
	if (data.size == 2)
		ft_solve_2a(data);
	if (data.size == 3)
		ft_solve_3a(data);
	if (data.size == 4)
		ft_solve_4a(data);
	if (data.size > 4)
	{
		ft_swapsort(data);
	}
}

void	ft_solve_2a(t_sort_data data)
{
	if ((*data.top_a)->index > (*data.top_a)->next->index)
		ft_swap_a(*data.top_a);
}

void	ft_solve_3a(t_sort_data data)
{
	ft_hustle(data);
	if ((*data.top_a)->next->index > (*data.top_a)->next->next->index)
	{
		ft_rotate(data.top_a, "ra");
		ft_hustle(data);
		ft_rev_rotate(data.top_a, "rra");
	}
	ft_hustle(data);
}

void	ft_solve_4a(t_sort_data data)
{
	int	min;
	int	max;

	min = get_min(data.size, *data.top_a);
	max = min + data.size - 1;
	// write(1, "foo", 3);
	if (ft_offset_index(*data.top_a, 2) == max)
	{
		ft_hustle(data);
		ft_rotate_x(data.top_a, "ra", 2);
		ft_hustle(data);
		ft_revr_x(data.top_a, "rra", 1);
		ft_hustle(data);
		ft_revr_x(data.top_a, "rra", 1);
		ft_hustle(data);
		// write(1, "bar", 3);
		// ra ra sa rra rra
	}
	else if (ft_offset_index(*data.top_a, 1) == max)
	{
		ft_rotate(data.top_a, "ra");
		ft_hustle(data);
		ft_rotate(data.top_a, "ra");
		ft_hustle(data);
		ft_revr_x(data.top_a, "rra", 2);
		ft_solve_3a(data);
		// write(1, "nin", 3);
		// ra sa ra sa rra rra
	}
	else if ((*data.top_a)->index == max)
	{
		// pb ra ra ra pa rra rra rra
		ft_push(data.top_a, data.top_b, "pb");
		ft_hustle(data);
		ft_rotate_x(data.top_a, "ra", 3);
		ft_push(data.top_b, data.top_a, "pa");
		ft_revr_x(data.top_a, "rra", 2);
		ft_hustle(data);
		ft_revr_x(data.top_a, "rra", 1);
		ft_hustle(data);
		// write(1, "faa", 3);
	}
}