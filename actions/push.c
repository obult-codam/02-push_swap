#include "push_swap.h"
#include "libft.h"

void	ft_push(t_stack **origin, t_stack **dest, char *msg)
{
	t_stack	*og_cpy;
 
	og_cpy = *origin;
	(og_cpy->prev)->next = og_cpy->next;
	(og_cpy->next)->prev = og_cpy->prev;
	*origin = og_cpy->next;
	if (*dest)
	{
		((*dest)->prev)->next = og_cpy;
		og_cpy->prev = (*dest)->prev;
		og_cpy->next = *dest;
		(*dest)->prev = og_cpy;
		*dest = og_cpy;
	}
	else
	{
		*dest = og_cpy;
		og_cpy->next = og_cpy;
		og_cpy->prev = og_cpy;
	}
	ft_putendl_fd(msg, 1);
}

void	ft_bottom_push(t_stack **org, t_stack **dst, char from)
{
	char	rotate[3];
	char	push[2];

	rotate[0] = 'r';
	rotate[1] = 'r';
	rotate[2] = from;
	push[0] = 'p';
	push[1] = from;
	ft_rev_rotate(org, rotate);
	ft_push(org, dst, push);
}

void	ft_bottom_push_x(t_stack **org, t_stack **dst, char from, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		ft_bottom_push(org, dst, from);
		i++;
	}
}
