#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_input		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;

	// printf("%p\n", list);
	ft_index_list(argc, argv, &list, &indexing);
	// printf("%p\n", list);
	// printf("%i\n", list->index);
	write_list_nbr(0, list);
	return (0);
}
