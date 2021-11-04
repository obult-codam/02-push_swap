#include "libft.h"
#include "push_swap.h"

int	ft_index_list(int argc, char **argv, t_input **list, t_indexing **indexing)
{
	int	i;
	t_input	*save;
	t_input	**store;

	i = 1;
	store = list;
	while (i < argc)
	{
		if (i == 1)
			*list = lstadd_input(*list);
		else
		{
			save = lstadd_input(*list);
			list = &save;
		}
		if (!*list || !lstadd_index(indexing, &((*list)->index), ft_atoi(argv[i])))
		{
			//nuke_all(pointers);
			//return(error!);
		}
		i++;
	}
	// set indexes based on t_indexing *indexing
	set_index(*indexing);
	// connect first piece of list to last piece of list by setting list->prev
	(*store)->prev = save;
	(*list)->next = *store;
	return (0);
}

t_input	*lstadd_input(t_input *last)
{
	if (!last)
		return (lstnew_input(last));
	last->next = lstnew_input(last);
	return (last->next);
}

t_indexing	*lstadd_index(t_indexing **lst, int *index, int nbr)
{
	while (*lst && (*lst)->nbr < nbr)
	{
		 lst = &((*lst)->next);
	}
	if (*lst && (*lst)->nbr == nbr)
		return (NULL);
	*lst = lstnew_index(*lst, index, nbr);
	return (*lst);  
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
