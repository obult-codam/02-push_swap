/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:05:36 by obult         #+#    #+#                 */
/*   Updated: 2021/12/16 20:02:54 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_pa(t_sort_data data)
{
	if (*data.top_b)
		ft_push(data.top_b, data.top_a, NULL);
	return (0);
}

int	ft_do_pb(t_sort_data data)
{
	if (*data.top_a)
		ft_push(data.top_a, data.top_b, NULL);
	return (0);
}
