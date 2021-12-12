#include "libft.h"
#include "push_swap.h"

// better name for input functions (stack or something else?)
int	ft_index_list(int argc, char **argv, t_stack **list, t_indexing **indexing)
{
	int		i;
	int		atoi_error;
	t_stack	*save;
	t_stack	**store;

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
		if (!*list || !lstadd_index(indexing, &((*list)->index),
				fo_atoi(argv[i], &atoi_error)))
			return (0);
		if (atoi_error == 0)
			return (0);
		i++;
	}
	set_index(*indexing);
	(*store)->prev = save;
	(*list)->next = *store;
	return (1);
}

t_stack	*lstadd_input(t_stack *last)
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

t_stack	*lstnew_input(t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (new);
	new->prev = prev;
	new->next = 0;
	return (new);
}
