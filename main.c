#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;
	t_stack		*b;
	// t_sort_data	data;

	indexing = 0;
	list = 0;
	b = 0;
	
	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		printf("error\n");
		nuke_all(list, NULL, indexing);
		return (1);
	}
	else
	{
		// solve
		ft_push(&list, &b, "msg");
		ft_push(&list, &b, "msg2");
		// ft_rotate(&list);	//
		write_list_nbr(list->prev, list);
		write(1, "\n", 1);
		write_list_nbr(b->prev, b);
		write(1, "\n", 1);
		nuke_all(list, b, indexing);
	}
	return (0);
}
