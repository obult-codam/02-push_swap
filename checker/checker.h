/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:47:18 by obult         #+#    #+#                 */
/*   Updated: 2021/12/16 18:53:17 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	ft_check_sorting(t_stack **stack_a, int size);
int	ft_check_line(t_sort_data data, char *line);

int	ft_do_sa(t_sort_data data);
int	ft_do_sb(t_sort_data data);
int	ft_do_ss(t_sort_data data);

int	ft_do_pa(t_sort_data data);
int	ft_do_pb(t_sort_data data);

int	ft_do_ra(t_sort_data data);
int	ft_do_rb(t_sort_data data);
int	ft_do_rr(t_sort_data data);

int	ft_do_rra(t_sort_data data);
int	ft_do_rrb(t_sort_data data);
int	ft_do_rrr(t_sort_data data);

int	ft_check_sorted(t_sort_data data);

#endif