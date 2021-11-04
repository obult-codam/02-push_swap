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

// is ugly needs rework
int	nuke_all(t_stack *a_stack, t_stack *b_stack, t_indexing *indexing)
{
	void	*tmp;

	while (a_stack)
	{
		tmp = a_stack->next;
		free(a_stack);
		a_stack = tmp;
	}
	while (b_stack)
	{
		tmp = b_stack->next;
		free(b_stack);
		b_stack = tmp;
	}
	while (indexing)
	{
		tmp = indexing->next;
		free(indexing);
		indexing = tmp;
	}
	return (0);
}

// void	nuke(void *list)
// {
// 	if (list)
// 	{
// 		nuke(list->next);
// 		free(list);
// 	}
// }

void	write_list_nbr(t_stack *last, t_stack *item)
{
	if (item != last)
	{
		ft_putnbr_fd(item->index, 1);
		// write(1, "foo\n", 4);
		write_list_nbr(last, item->next);
	}
	else if (item != NULL)
		ft_putnbr_fd(item->index, 1);
}