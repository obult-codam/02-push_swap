/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:31:30 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:31:30 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
