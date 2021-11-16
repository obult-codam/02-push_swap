// this is meant to solve up to 5 items from stack B back to stack A
// It starts by looking for the highest two numbers on stack B and pushing both to stack A in any order
// if highest is first then do the same for the next two highest
// next step is swap on stack A if needed

// this should be able to solve anything coming from stack B

// this is not working yet and only solves the first two items (but effeciently!)

void	ft_solve_on_b(t_sort_data data)
{
	int	r;

	if (data.size == 1)
		ft_push(data.top_b, data.top_a, "pb");
	else if (data.size > 1)
	{
		r = ft_quicksolve(data);
		ft_revr_x(data.top_b, "rrb", r);
		data.size = data.size - 2;
		ft_solve_on_b(data);
	}
}

int	ft_quicksolve(t_sort_data data)
{
	int	max;
	int	i;
	int	r;

	i = 0;
	r = 0;
	max = data.size + getmin(data.size, *data.top_b) - 1;
	while (i < data.size)
	{
		if ((*data.top_b)->index >= max - 1)
		{
			ft_push(data.top_b, data.top_a, "pb");
			if ((*data.top_a)->index == max)
			{
				ft_hustle(data);
				max--;
				if ((*data.top_a)->index == max)
					max--;
			}
			else
			{
				ft_solve_2a(data);
			}
		}
		else
		{
			ft_rotate(data.top_b, "rb");
			r++;
		}
		i++;
	}
	return (r);
}

void	ft_hustle(t_sort_data data)
{
	if ((*data.top_a)->index > (*data.top_a)->next->index)
	{
		if ((*data.top_b)->index < (*data.top_b)->next->index)
		{
			ft_swap(*data.top_a);
			ft_swap(*data.top_b);
			ft_putendl_fd("ss", 1);
		}
		else
			ft_swap_a(*data.top_a);
	}
}
