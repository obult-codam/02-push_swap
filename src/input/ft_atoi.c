/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 22:18:01 by obult         #+#    #+#                 */
/*   Updated: 2021/12/12 17:23:24 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int		charcheck(char tch, char *check)
{
	if (!(*check))
		return (0);
	if (tch == *check)
		return (1);
	return (charcheck(tch, check + 1));
}

int				fo_atoi(const char *nptr, int *error)
{
	int		i;
	int		plus;
	int		result;

	i = 0;
	plus = 1;
	result = 0;
	while (charcheck(nptr[i], " \t\v\r\f\n"))
		i++;
	if (charcheck(nptr[i], "-+"))
		if (nptr[i] == '-')
			plus = -1;
	if (charcheck(nptr[i], "-+"))
		i++;
	while (charcheck(nptr[i], "0123456789"))
	{
		if (result > (2147483648 / 10) && plus == -1)
		{
			*error = 0;
			return (0);
		}
		if (result > (2147483647 / 10))
		{
			*error = 0;
			return (0);
		}
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (nptr[i])
	{
		*error = 0;
		return (0);
	}
	return (result * plus);
}
