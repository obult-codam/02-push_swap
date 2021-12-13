/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:28:40 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:37:10 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*list;
	t_indexing	*indexing;

	indexing = 0;
	list = 0;
	if (argc < 2)
		return (0);
	if (is_sorted(argc, argv) == 1)
		return (0);
	else if (is_sorted(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ft_index_list(argc, argv, &list, &indexing))
	{
		write(2, "Error\n", 6);
		nuke_all(list, NULL, indexing);
		return (1);
	}
	ft_sort_parent(&list, argc - 1);
	nuke_all(list, NULL, indexing);
	return (0);
}
