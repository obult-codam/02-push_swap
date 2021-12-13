/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksolve.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:32:07 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:35:01 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_send_2ba(t_sort_data data)
{
	int	i;
	int	r;
	int	max;

	i = 0;
	r = 0;
	max = data.size + get_min(data.size, *data.top_b) - 1;
	while (i < data.size)
	{
		if (i - r == 2)
			break ;
		if ((*data.top_b)->index >= max - 1)
		{
			ft_push(data.top_b, data.top_a, "pa");
			ft_hustle(data);
		}
		else
		{
			ft_rotate(data.top_b, "rb");
			r++;
		}
		i++;
	}
	return (r);
}

void	ft_solve_on_b(t_sort_data data)
{
	int	r;

	while (data.size)
	{
		if (data.size > 1)
		{
			r = ft_send_2ba(data);
			ft_revr_x(data.top_b, "rrb", r);
			data.size = data.size - 2;
		}
		else if (data.size == 1)
		{
			ft_push(data.top_b, data.top_a, "pa");
			data.size--;
		}
	}
}

// could do function below with recursively growing int i; if needed 
// to make shorter would skip while loop

int	push_one_a(int range_start, int range_end, t_sort_data data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_offset_index(*data.top_b, -1 * i) <= range_end
			&& ft_offset_index(*data.top_b, -1 * i) >= range_start)
		{
			ft_revr_x(data.top_b, "rrb", i);
			ft_push(data.top_b, data.top_a, "pa");
			if ((*data.top_a)->index == range_end)
				return (1);
			return (0);
		}
		else if (ft_offset_index(*data.top_b, i) <= range_end
			&& ft_offset_index(*data.top_b, i) >= range_start)
		{
			ft_rotate_x(data.top_b, "rb", i);
			ft_push(data.top_b, data.top_a, "pa");
			if ((*data.top_a)->index == range_end)
				return (1);
			return (0);
		}
		i++;
	}
}

void	ft_push_fast_first(t_sort_data data, int size, int min)
{
	int	high;

	high = min + size - 1;
	if (size == 1)
	{
		push_one_a(min, min, data);
	}
	else if (push_one_a(high - 1, high, data))
	{
		high--;
		ft_push_fast_first(data, size - 1, min);
	}
	else
	{
		push_one_a(high, high, data);
		ft_hustle(data);
		if (size <= 2)
			return ;
		ft_push_fast_first(data, size - 2, min);
	}
}

void	ft_fast_five_b(t_sort_data data)
{
	int	min;

	min = get_min(data.size, *data.top_b);
	ft_push_fast_first(data, data.size, min);
}
