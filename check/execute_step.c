/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_step.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 15:56:33 by obult         #+#    #+#                 */
/*   Updated: 2021/12/17 16:23:21 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Libft/libft.h"
#include "checker.h"

int	ft_check_line(t_sort_data data, char *line)
{
	if (ft_memcmp(line, "sa", 3) == 0)
		return (ft_do_sa(data));
	if (ft_memcmp(line, "sb", 3) == 0)
		return (ft_do_sb(data));
	if (ft_memcmp(line, "ss", 3) == 0)
		return (ft_do_ss(data));
	if (ft_memcmp(line, "pa", 3) == 0)
		return (ft_do_pa(data));
	if (ft_memcmp(line, "pb", 3) == 0)
		return (ft_do_pb(data));
	if (ft_memcmp(line, "ra", 3) == 0)
		return (ft_do_ra(data));
	if (ft_memcmp(line, "rb", 3) == 0)
		return (ft_do_rb(data));
	if (ft_memcmp(line, "rr", 3) == 0)
		return (ft_do_rr(data));
	if (ft_memcmp(line, "rra", 3) == 0)
		return (ft_do_rra(data));
	if (ft_memcmp(line, "rrb", 3) == 0)
		return (ft_do_rrb(data));
	if (ft_memcmp(line, "rrr", 3) == 0)
		return (ft_do_rrr(data));
	return (-2);
}
