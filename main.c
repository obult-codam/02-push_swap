#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_input		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;

	ft_index_list(argc, argv, &list, &indexing);
	write_list_nbr(list->prev, list);
	return (0);
}
