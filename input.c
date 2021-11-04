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

void	write_list_nbr(t_input *last, t_input *item)
{
	if (item != NULL)
	{
		ft_putnbr_fd(item->index, 1);
		// write(1, "foo\n", 4);
		write_list_nbr(last, item->next);
	}
	// else
	// ft_putnbr_fd(item->index, 1);
}