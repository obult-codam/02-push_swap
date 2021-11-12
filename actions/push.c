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
