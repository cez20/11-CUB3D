#include "../include/cub3d.h"

static int	is_set(char c, char *set)
{
	int	i;

	if (!c || !set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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
	if ((is_out(x, y, game) && ft_strchr("0 ", game->map_copy[x][y])) || game->map_copy[x][y] == ' ')
		errmsg(ERR_INTEGRITY, 1, game); // errormsg, free, exit
	if (game->map_copy[x][y] == '0' || is_set(game->map_copy[x][y], "NSWE")) // if i do this, i'll have to make sure player_x and y are kept safe in t_game because i'll lose the letter reference inside the map. or, make and work on a copy.
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
