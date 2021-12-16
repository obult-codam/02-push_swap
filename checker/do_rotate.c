/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:09:41 by obult         #+#    #+#                 */
/*   Updated: 2021/12/16 18:57:15 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_ra(t_sort_data data)
{
	ft_rotate(data.top_a, NULL);
	return (0);
}

int	ft_do_rb(t_sort_data data)
{
	ft_rotate(data.top_b, NULL);
	return (0);
}

int	ft_do_rr(t_sort_data data)
{
	ft_rotate(data.top_a, NULL);
	ft_rotate(data.top_b, NULL);
	return (0);
}