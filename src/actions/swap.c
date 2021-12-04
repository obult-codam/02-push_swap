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

void	ft_swapsort(t_sort_data data)
{
	if (data.size < 4)
	{
		ft_solve_3a(data);
		return ;
	}
	ft_solve_2a(data);
	ft_swapsolve(data);
	data.size = data.size -1;
	ft_swapsort(data);
}

void	ft_swapsolve(t_sort_data data)
{
	if (data.size - 2 > 0)
	{
		ft_rotate(data.top_a, "ra");
		ft_solve_2a(data);
		data.size = data.size - 1;
		ft_swapsolve(data);
		ft_rev_rotate(data.top_a, "rra");
		ft_solve_2a(data);
	}
}
