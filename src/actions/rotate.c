#include "push_swap.h"
#include "libft.h"

void	ft_rotate(t_stack **r, char *msg)
{
	*r = (*r)->next;
	ft_putendl_fd(msg, 1);
}

void	ft_rotate_x(t_stack **r, char *msg, int rotations)
{
	int	i;

	i = 0;
	if (*r == ft_get_bottom_offset(*r, rotations))
		return ;
	while (i < rotations)
	{
		ft_rotate(r, msg);
		i++;
	}
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
	if (*r == ft_get_bottom_offset(*r, rotations))
		return ;
	while (i < rotations)
	{
		ft_rev_rotate(r, msg);
		i++;
	}
}
