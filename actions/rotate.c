#include "push_swap.h"
#include "libft.h"

void	ft_rotate(t_stack **r, char *msg)
{
	*r = (*r)->next;
	ft_putendl_fd(msg, 1);
}

void	ft_rev_rotate(t_stack **r, char *msg)
{
	*r = (*r)->prev;
	ft_putendl_fd(msg, 1);
}

void	ft_revr_x(t_stack **r, char *msg, int rotations)
{
	int	i;

	i = 0;
	while (i < rotations)
	{
		ft_rev_rotate(r, msg);
		i++;
	}
}
