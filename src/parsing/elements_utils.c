#include "../include/cub3d.h"

int	is_floor_or_ceiling(char *str)
{
	if ((ft_strncmp(str, "F ", 2) == 0)
		|| (ft_strncmp(str, "C ", 2) == 0))
		return (1);
	return (0);
}

int		nb_of_strings(char **str)
{
	int i;
	int j;

	i = 0;

	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		i++;
	}
	return (i);
}

int ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
	|| c == '\f' || c == '\r')
		return (1);
	return (0);
}