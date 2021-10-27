#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	ft_putnbr_fd(argc, 1);
	add_printarray_fd(argv, 1);
	return (0);
}
