#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	t_input		*list;
	t_indexing	*indexing;

	list = 0;
	indexing =0;
	ft_index_list(argc, argv, &list, &indexing)
}


int	ft_index_list(int argc, char **argv, t_input **list, t_indexing **indexing)
{
	int	i;
	t_input	*last;

	last = *list;
	i = 1;
	while (1 < argc)
	{
		last = lstadd_input(last);
		if (!last || !lstadd_index(indexing, &last->index, ft_atoi(argv[i])));
		{
			//nuke_all(pointers);
			//return(error!);
		}
		i++;
	}
	// set indexes based on t_indexing *indexing
	// connect first piece of list to last piece of list by setting list->prev
}

lstadd_input(t_input *last)
{
	// last is last item in the list so entry can 
	// be added as next previous needs to be set as what is given in last
	if (!last)
		return (lstnew_input(last));
	last->next = lstnew_input(last);
	return (last->next);
}

lstadd_index(t_indexing **first, int *index, int nbr)
{
	// new item must be made and placed in right spot in the list based on nbr
	// new.nbr needs to be set to nbr
	// new.index = index
	t_indexing	iterator;

	iterator = *first;
	if (!*first)
	{
		*first = lstnew_index(0, index, nbr);
		return (*first);
	}
	while (iterator && iterator->nbr < nbr)
	{
		 iterator = iterator->next;
	}
	iterator = lstnew_index(iterator->next, index, nbr);
	return (iterator);  
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