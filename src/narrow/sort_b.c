#include "push_swap.h"
#include "libft.h"

void	ft_sort_b(t_sort_data data)
{
	if (data.size < 8)
	{
		ft_fast_five_b(data);
	}
	else
	{
		ft_split_in_two(data);
	}
}
