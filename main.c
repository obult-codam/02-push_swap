#include "libft.h"
#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;
	// t_stack		*b;
	// t_sort_data	data;

	indexing = 0;
	list = 0;
	// b = 0;
	
	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		printf("error\n");
		nuke_all(list, NULL, indexing);
		return (1);
	}
	else
	{
		// solve
		// ft_push(&list, &b, "msg");
		// ft_push(&list, &b, "msg2");
		// ft_rotate(&list);	//
		write_list_nbr(list->prev, list);
		write(1, "\n", 1);
		// write_list_nbr(b->prev, b);
		// write(1, "\n", 1);
		nuke_all(list, NULL, indexing);
	}
	return (0);
}
