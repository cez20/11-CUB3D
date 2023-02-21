#include "../include/cub3d.h"

//This function indicates player position: North, East, West, South (NEWS)
int	is_news(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

void	player_position(t_game *game, int x, int y)
{
	if (game->nb_player == 0)
	{
		game->player_x = x;
		game->player_y = y;
		game->nb_player++;
	}
	else
		game->nb_player++;
}

// Ft_strncmp gives a result of 0 when the str and the elements are identical
//When not identical gives a number higher than 0. If ALL comparisons, gives a
// number higher than 0, it means that is an invalid element.  
int is_valid_element(char *str)
{
	if ((ft_strncmp(str, "NO ", 3) != 0) 
		&& (ft_strncmp(str, "SO ", 3) != 0)
		&& (ft_strncmp(str, "EA ", 3) != 0)
		&& (ft_strncmp(str, "WE ", 3) != 0)
		&& (ft_strncmp(str, "F ", 2) != 0)
		&& (ft_strncmp(str, "C ", 2)) != 0)
		return (1);
	return (0);
}

void	verify_elements(t_game *game)
{
	int	i;

	i = 0;
	print_game(game->elements_copy);
	while (game->elements_copy[i])
	{
		if (is_direction(game->elements_copy[i]))
			check_direction(game->elements_copy[i])
		else if (floor_or_ceiling(game->elements_copy[i]))
			check_colors
		else
			errmsg(ERR_CONTENT, 1, game);
		i++;
	}
}

void	verify_map_characters(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->map_copy[i])
	{
		j = 0;
		while (g->map_copy[i][j])
		{
			if (is_wall(g->map_copy[i][j]) || is_news(g->map_copy[i][j]) ||
			ft_isset(g->map_copy[i][j], "-"))
			{
				if (is_news(g->map_copy[i][j]))
					player_position(g, i, j);
			}
			else
				errmsg(ERR_CONTENT, 1, g);
			j++;
		}
		i++;
	}
	if (g->nb_player < 1 || g->nb_player > 1)
		errmsg(ERR_CONTENT, 1, g);
	printf("player(%f, %f)\n", g->player_x, g->player_y);
}

// If we mix tab and whitespaces, the different sizes breaks validation. To be checked.

void	game_parsing(t_game *game)
{
	verify_elements(game);
	verify_map_characters(game);
	verify_map_walls(game);
	replace_map_spaces(game);
}
