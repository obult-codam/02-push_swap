#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

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

// is ugly needs rework now just rework indexing
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

void	write_list_nbr(t_stack *last, t_stack *item)
{
	if (last == NULL || item == NULL)
		return ;
	if (item != last)
	{
		ft_putnbr_fd(item->index, 1);
		ft_putchar_fd(' ', 1);
		write_list_nbr(last, item->next);
	}
	else if (item != NULL)
		ft_putnbr_fd(item->index, 1);
}