#include "../include/cub3d.h"

static int	is_out(int x, int y, t_game *game)
{
	if ((x - 1 < 0)
		|| (y - 1 < 0)
		|| (x + 1 >= game->map_height)
		|| (size_t)y + 1 >= ft_strlen(game->map_copy[x]))
		return (1);
	else
		return (0);
}

void	flood_fill(int x, int y, t_game *game)
{
	if ((is_out(x, y, game) && ft_strchr("0 ", game->map_copy[x][y])) \
		|| game->map_copy[x][y] == ' ')
		errmsg(ERR_INTEGRITY, 1, game);
	if (game->map_copy[x][y] == '0' || ft_isset(game->map_copy[x][y], "NSWE")) // if i do this, i'll have to make sure player_x and y are kept safe in t_game because i'll lose the letter reference inside the map. or, make and work on a copy.
		game->map_copy[x][y] = '.';
	else
		return ;
	flood_fill(x - 1, y, game);
	flood_fill(x, y + 1, game);
	flood_fill(x + 1, y, game);
	flood_fill(x, y - 1, game);
	flood_fill(x + 1, y + 1, game);
	flood_fill(x - 1, y + 1, game);
	flood_fill(x + 1, y - 1, game);
	flood_fill(x - 1, y - 1, game);
}

//---VERSION CESAR  
// void	flood_fill(int x, int y, t_game *game)
// {
// 	if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width)
// 		return ;
// 	if (game->map_copy[x][y] != '-')
// 	{
// 		if (game->map_copy[x][y] == '0')
// 			errmsg(ERR_MAP_WALLS, 1, game); //Risque de creer des leaks, car l'ensemble des appels des fonctions, ne seront pas termine??
// 			//game->error = 1;
// 		return ;
// 	}
// 	game->map_copy[x][y] = '.';
// 	flood_fill(x - 1, y, game);
// 	flood_fill(x, y + 1, game);
// 	flood_fill(x + 1, y, game);
// 	flood_fill(x, y - 1, game);
// 	flood_fill(x + 1, y + 1, game);
// 	flood_fill(x - 1, y + 1, game);
// 	flood_fill(x + 1, y - 1, game);
// 	flood_fill(x - 1, y - 1, game);
// }

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

void	skip_whitespaces(char **str)
{
	if (!*str || !**str)
		return ;
	while (**str && ft_isset(**str, WHITESPACE))
		*str += 1;
	return ;
}