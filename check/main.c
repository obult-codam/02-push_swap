/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 15:44:02 by obult         #+#    #+#                 */
/*   Updated: 2021/12/16 18:55:30 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;
	if (argc < 2)
		return (0);
	else if (is_sorted(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		write(2, "Error\n", 6);
		nuke_all(list, indexing);
		return (1);
	}
	ft_check_sorting(&list, argc - 1);
	nuke_all(list, indexing);
	return (0);
}

void	ft_check_sorting(t_stack **stack_a, int size)
{
	t_sort_data	data;
	t_stack		*b;
	char		*line;

	data.top_a = stack_a;
	b = 0;
	data.top_b = &b;
	data.size = size;
	while (get_next_line(0, &line))
	{
		if (ft_check_line(data, line) == -1)
			break ;
	}
	if (ft_check_sorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	nuke_all(b, NULL);
}
