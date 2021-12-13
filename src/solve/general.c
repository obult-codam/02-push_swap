/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:31:59 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:32:00 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_on_a(t_sort_data data)
{
	if (data.size == 1)
		return ;
	if (data.size == 2)
		ft_solve_2a(data);
	if (data.size == 3)
		ft_solve_3a(data);
	if (data.size > 3)
		ft_swapsort(data);
}

void	ft_solve_2a(t_sort_data data)
{
	if ((*data.top_a)->index > (*data.top_a)->next->index)
		ft_swap_a(*data.top_a);
}

void	ft_solve_3a(t_sort_data data)
{
	ft_hustle(data);
	if ((*data.top_a)->next->index > (*data.top_a)->next->next->index)
	{
		ft_rotate(data.top_a, "ra");
		ft_hustle(data);
		ft_rev_rotate(data.top_a, "rra");
	}
	ft_hustle(data);
}

void	ft_swapsort(t_sort_data data)
{
	if (data.size < 4)
	{
		ft_solve_3a(data);
		return ;
	}
	ft_hustle(data);
	ft_swapsolve(data);
	data.size = data.size - 1;
	ft_swapsort(data);
}

void	ft_swapsolve(t_sort_data data)
{
	if (data.size - 2 > 0)
	{
		ft_rotate(data.top_a, "ra");
		ft_hustle(data);
		data.size = data.size - 1;
		ft_swapsolve(data);
		ft_rev_rotate(data.top_a, "rra");
		ft_hustle(data);
	}
}
