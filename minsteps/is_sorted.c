#include "libft.h"

int	is_sorted(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) >= ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
