/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_series.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:33:36 by obult         #+#    #+#                 */
/*   Updated: 2021/12/16 18:56:23 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_sort_data data)
{
	int	prev_index;
	int	i;

	i = 0;
	prev_index = (*data.top_a)->index;
	while (i < data.size)
	{
		if (!(*data.top_a))
			return (0);
		if (prev_index > (*data.top_a)->index)
			return (0);
		prev_index = (*data.top_a)->index;
		*data.top_a = (*data.top_a)->next;
		i++;
	}
	return (1);
}