#include "libft.h"
#include "push_swap.h"


typedef struct s_sort_data
{
	t_stack		**top_a;
	t_stack		**top_b;
	t_stack		*start;
	t_stack		*end;
	int			size;
}	t_sort_data;

void	ft_sort_parent(t_stack *top_a, int total_nbrs)
{
	t_stack	*b;


}

void	ft_sort(t_stack *top_a, t_stack *b, int size)
{
	if (size < 6)
		ft_solve_on_a(size)
	else
	{
		split_in_groups()
	}
}

void	split_in_groups(t_sort_data data)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	data.min = &min;
	data.max = &max;
	data.size = max - min;
	get_minmax(data);
	while (i < size)
	{
		if ((*data.top_a)->index < min + size / 3)
		{
			push_a()
			rotate_b()
		}
		else if ((*data.top_a)->index < min + (size / 3) * 2)
		{
			push_a()
		}
		else
		{
			rotate_a()
		}
	}
	
}

void	get_minmax(t_sort_data data)
{
	int		i;

	i = 0;
	*data.min = data.start->index;
	*data.max = data.start->index;
	while (i < data.size)
	{
		if (data.start->index > *data.max)
			*data.max = data.start->index;
		if (data.start->index < *data.min)
			*data.min = data.start->index;
		i++;
		data.start = data.start->next;
	}
	return (min);
}