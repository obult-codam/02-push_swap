#include "libft.h"
#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;
	if (is_sorted(argc, argv))
		return (0);
	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		write(2, "Error\n", 6);
		nuke_all(list, NULL, indexing);
		return (1);
	}
	else
	{
		ft_sort_parent(&list, argc - 1); 
		// write_list_nbr(list->prev, list);
		// write(1, "\n", 1);
		nuke_all(list, NULL, indexing);
	}
	return (0);
}
