#include "../include/cub3d.h"

// // Ft_strncmp gives a result of 0 when the str and the elements are identical
// //When not identical gives a number higher than 0. If ALL comparisons, gives a
// // number higher than 0, it means that is an invalid element.  
// int is_valid_element(char *str)
// {
// 	if ((ft_strncmp(str, "NO ", 3) != 0) 
// 		&& (ft_strncmp(str, "SO ", 3) != 0)
// 		&& (ft_strncmp(str, "EA ", 3) != 0)
// 		&& (ft_strncmp(str, "WE ", 3) != 0)
// 		&& (ft_strncmp(str, "F ", 2) != 0)
// 		&& (ft_strncmp(str, "C ", 2)) != 0)
// 		return (1);
// 	return (0);
// }

// int	is_cardinal_direction(char *str)
// {
// 	if ((ft_strncmp(str, "NO", 2) == 0)
// 		|| (ft_strncmp(str, "SO", 2) == 0)
// 		|| (ft_strncmp(str, "EA", 2) == 0)
// 		|| (ft_strncmp(str, "WE", 2)) == 0)
// 		return (1);
// 	return (0);
// }

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