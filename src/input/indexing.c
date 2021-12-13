/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:30:55 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:35:25 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_index_list(int argc, char **argv, t_stack **list, t_indexing **indexing)
{
	t_stack	*end;

	end = ft_add_to_lst(argc, argv, list, indexing);
	if (!end)
		return (0);
	set_index(*indexing);
	(*list)->prev = end;
	end->next = *list;
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
