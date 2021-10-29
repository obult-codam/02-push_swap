#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	ft_putnbr_fd(argc, 1);
	add_printarray_fd(argv, 1);
	return (0);
}


int	ft_index_list(int argc, char **argv, t_input *first, t_indexing *indexing)
{
	int	i;

	i = 1;
	while (1 < argc)
	{
		list = lstadd_input(list);
		if (!list || !lstadd_index(indexing, &list->index, ft_atoi(argv[i])));
		{
			//nuke_all(pointers);
			//return(error!);
		}
		i++;
	}
	// set indexes based on t_indexing *indexing
	// connect first piece of list to last piece of list by setting list->prev (maybe call first?)
}

lstadd_input(t_input *last)
{
	// last is last item in the list so entry can 
	// be added as next previous needs to be set as what is given in last

	last->next = lstnew_input(last);

}

lstadd_index(t_indexing *first, int *index, int nbr)
{
	// new item must be made and placed in right spot in the list based on nbr
	// new.nbr needs to be set to nbr
	// new.index = index

}

t_indexing	*lstnew_index(t_indexing *next, int *index, int nbr)
{
	t_indexing	*new;

	new = malloc(sizeof(t_indexing));
	if (!new)
		return (new);
	new->next = next;
	new->index = index;
	new->nbr = nbr;
	return (new);
}

t_input	*lstnew_input(t_input *prev)
{
	t_input *new;

	new = malloc(sizeof(t_input));
	if (!new)
		return (new);
	new->prev = prev;
	new->next = 0;
	return (new);
}