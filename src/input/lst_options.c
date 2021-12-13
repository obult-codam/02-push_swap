/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_options.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:31:03 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:31:06 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_add_to_lst(int argc, char **argv, t_stack **list, t_indexing **idx)
{
	int		i;
	int		atoi_error;
	t_stack	*save;

	i = 1;
	atoi_error = 1;
	while (i < argc)
	{
		if (i == 1)
			*list = lstadd_input(*list);
		else
		{
			save = lstadd_input(*list);
			list = &save;
		}
		if (!*list || !lstadd_index(idx, &((*list)->index),
				fo_atoi(argv[i], &atoi_error)))
			return (0);
		if (atoi_error == 0)
			return (0);
		i++;
	}
	return (save);
}

void	set_index(t_indexing *indexing)
{
	int	i;

	i = 0;
	while (indexing)
	{
		*(indexing->index) = i;
		i++;
		indexing = indexing->next;
	}
}

void	nuke_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (stack && stack->prev)
		(stack->prev)->next = 0;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	nuke_all(t_stack *a_stack, t_stack *b_stack, t_indexing *indexing)
{
	void	*tmp;

	nuke_stack(a_stack);
	nuke_stack(b_stack);
	while (indexing)
	{
		tmp = indexing->next;
		free(indexing);
		indexing = tmp;
	}
	return (0);
}

void	write_list_nbr(t_stack *item, t_stack *last)
{
	if (item == NULL)
		return ;
	if (last == NULL)
		last = item->prev;
	if (item != last)
	{
		ft_putnbr_fd(item->index, 1);
		ft_putchar_fd(' ', 1);
		write_list_nbr(item->next, last);
	}
	else if (item != NULL)
	{
		ft_putnbr_fd(item->index, 1);
		write(1, "\n", 1);
	}
}
