#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;

	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		printf("error\n");
		nuke_all(list, NULL, indexing);
		return (1);
	}
	write_list_nbr(list->prev, list);
	write(1, "\n", 1);
	return (0);
}
