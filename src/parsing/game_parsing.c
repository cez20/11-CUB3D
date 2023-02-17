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

// int	is_valid_character(char *game)
// {
// 	if (ft_strnstr(game, "NO ", 3))
// 		return (1);
// 	else if (ft_strnstr(game, "SO ", 3))
// 		return 1;
// 	else if (ft_strnstr(game, "WE ", 3))
// 		return 1;
// 	else if (ft_strnstr(game, "EA ", 3))
// 		return 1;
// 	else if (ft_strnstr(game, "C  ", 3))
// 		return 1;
// 	else if (ft_strnstr(game, "F  ", 3))
// 		return 1;
// 	else if (ft_strnstr(game, "  ", 3))
// 		return 1;
// 	else
// 		return 0;
// }

// void	verify_game_elements(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (game->elements_copy[i])
// 	{
// 		j = 0;
// 		while(game->elements_copy[i][j])
// 		{
// 			if (is_valid_character(game->elements_copy[i]))
// 			{
// 				printf("Okay\n");
// 				j++;
// 			}
// 			else
// 				printf("Error\n");
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
			if (is_wall(g->map_copy[i][j]) || is_news(g->map_copy[i][j]) || ft_isset(g->map_copy[i][j], "-"))
			{
				if (is_news(g->map_copy[i][j]))
					player_position(g, i , j);
			}
			else
				errmsg(ERR_CONTENT, 1, g);
			j++;
		}
		i++;
	}
	if (g->nb_player < 1 || g->nb_player > 1)
		errmsg(ERR_CONTENT, 1, g);
	printf("player(%d, %d)\n", g->player_x, g->player_y);
}

// If we mix tab and whitespaces, the different sizes breaks validation. To be checked.

void	game_parsing(t_game *game)
{
	//verify_game_elements(game);
	verify_map_characters(game);
	verify_map_walls(game);
}
