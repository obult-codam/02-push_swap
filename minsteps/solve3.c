#include "push_swap.h"

void	min_solve_three(t_sort_data data)
{
	if ((*data.top_a)->index == 2)
		ft_rotate(data.top_a, "ra");
	else if ((*data.top_a)->next->index == 2)
		ft_rev_rotate(data.top_a, "rra");
	ft_solve_2a(data);
}

void	min_solve_five()
{
	where is the 5?
	where is the 4?
	can we swap?
	
}

// move closest 4 or 5 to stack b
// move second closest quickest pos to stack b
// solve 3 on A
// move back both of them from B
// solve 2a