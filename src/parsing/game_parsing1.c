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


void	check_direction(t_game *game, char *str)
{
	char	**tab;
	char	*new;
	int		i;
	int		fd;

	i = 0;
	tab = ft_split(str, ' ');
	if (nb_of_strings(tab) != 2)
		errmsg(ERR_ELEMENTS, 1, game);
	while (ft_is_whitespace(tab[1][i])) // Determiner si le fait qu'il y ait des tab avant ma texture est une erreur 
		i++;
	new = &tab[1][i];
	printf("The value of new is :%s\n", new);
	fd = open(new, O_RDONLY);
	if (fd == -1)
		errmsg(ERR_TEXTURE, 1, game);

}

int	is_cardinal_direction(char *str)
{
	if ((ft_strncmp(str, "NO", 2) == 0)
		|| (ft_strncmp(str, "SO", 2) == 0)
		|| (ft_strncmp(str, "EA", 2) == 0)
		|| (ft_strncmp(str, "WE", 2)) == 0)
		return (1);
	return (0);
}

int	is_floor_or_ceiling(char *str)
{
	if ((ft_strncmp(str, "F ", 2) == 0)
		|| (ft_strncmp(str, "C ", 2) == 0))
		return (1);
	return (0);
}


void	replace_map_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_copy[++i])
	{
		j = -1;
		while (game->map_copy[i][++j])
		{
			if (game->map_copy[i][j] == '-')
				game->map_copy[i][j] = '1';
		}
	}
	print_game(game->map_copy);
}

//My take on wall verification:
//I read the map left to right, top to bottom, checking certain conditions on zeroes only.
//First: If there are any 0's at the extremities: error;
//Else: If there are any spaces NOT surrounded by walls inside the map (holes filled with '-' character): error;
//This doesn't check for diagonals (though it could) because valid empty spaces would be filled with walls AFTER map validation, so that would prevent any bugs later on.
// Floodfill becomes useless at this point since we don't have to check for valid pathways, etc. (unless we decide later to add collectibles, etc)
void	verify_map_walls(t_game *game)
{
	int	i;
	int	j;

	print_game(game->map_copy);
	i = -1;
	while (game->map_copy[++i])
	{
		j = -1;
		while (game->map_copy[i][++j])
		{
			if (game->map_copy[i][j] == '0')
			{
				if ((i == 0 || i == game->map_height - 1)
					|| (j == 0 || j == game->map_width - 1))
					errmsg(ERR_MAP_WALLS, 1, game);
				else if (game->map_copy[i - 1][j] == '-'
						|| game->map_copy[i + 1][j] == '-'
						|| game->map_copy[i][j + 1] == '-'
						|| game->map_copy[i][j - 1] == '-'
						|| game->map_copy[i - 1][j - 1] == '-'
						|| game->map_copy[i - 1][j + 1] == '-'
						|| game->map_copy[i + 1][j + 1] == '-')
					errmsg(ERR_MAP_WALLS, 1, game);
			}
		}
	}
}
