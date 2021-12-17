/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_rev_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:13:43 by obult         #+#    #+#                 */
/*   Updated: 2021/12/17 16:23:42 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_rra(t_sort_data data)
{
	if (*data.top_a)
		ft_rev_rotate(data.top_a, NULL);
	return (0);
}

int	ft_do_rrb(t_sort_data data)
{
	if (*data.top_b)
		ft_rev_rotate(data.top_b, NULL);
	return (0);
}

int	ft_do_rrr(t_sort_data data)
{
	if (*data.top_a)
		ft_rev_rotate(data.top_a, NULL);
	if (*data.top_b)
		ft_rev_rotate(data.top_b, NULL);
	return (0);
}
