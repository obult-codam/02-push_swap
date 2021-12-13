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
