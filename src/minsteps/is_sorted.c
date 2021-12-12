#include "libft.h"
#include "push_swap.h"

static int	charcheck(char tch, char *check)
{
	if (!(*check))
		return (0);
	if (tch == *check)
		return (1);
	return (charcheck(tch, check + 1));
}

int	check_just_min(char *arg)
{
	int	i;

	i = 0;
	while (charcheck(arg[i], " \t\v\r\f\n"))
		i++;
	if (charcheck(arg[i], "-+"))
		i++;
	if (charcheck(arg[i], "0123456789"))
		return (0);
	return (1);
}

int	is_sorted(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	if (!fo_atoi(argv[i], &error))
		return (-1);
	while (i < argc - 1)
	{
		if (!fo_atoi(argv[i + 1], &error))
			return (-1);
		if (ft_atoi(argv[i]) >= ft_atoi(argv[i + 1]))
			return (0);
		if (check_just_min(argv[i]))
			return (-1);
		i++;
	}
	if (check_just_min(argv[i]))
		return (-1);
	return (1);
}
