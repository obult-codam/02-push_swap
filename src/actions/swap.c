#include "push_swap.h"
#include "libft.h"

void	ft_swap(t_stack *swap)
{
	int	save;

	save = swap->index;
	swap->index = (swap->next)->index;
	(swap->next)->index = save;
}

void	ft_swap_a(t_stack *swap)
{
	ft_swap(swap);
	ft_putendl_fd("sa", 1);
}

void	ft_swap_b(t_stack *swap)
{
	ft_swap(swap);
	ft_putendl_fd("sb", 1);
}

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
