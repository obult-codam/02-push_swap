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
