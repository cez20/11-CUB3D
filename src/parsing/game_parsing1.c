#include "../include/cub3d.h"

void	flood_fill(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width)
		return ;
	if (game->map_copy[x][y] != '-')
	{
		if (game->map_copy[x][y] == '0')
			errmsg(ERR_MAP_WALLS, 1, game); //Risque de creer des leaks, car l'ensemble des appels des fonctions, ne seront pas termine??
			//game->error = 1;
		return ;
	}
	game->map_copy[x][y] = '.';
	flood_fill(x - 1, y, game);
	flood_fill(x, y + 1, game);
	flood_fill(x + 1, y, game);
	flood_fill(x, y - 1, game);
	flood_fill(x + 1, y + 1, game);
	flood_fill(x - 1, y + 1, game);
	flood_fill(x + 1, y - 1, game);
	flood_fill(x - 1, y - 1, game);
}

void	verify_corner_walls(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while(game->map_copy[i][j])
		{
			if(game->map_copy[i][j] == '-')
				flood_fill(i, j, game);
			j++;
		}
		i++;
	}
	print_game(game->map_copy);
	//if (game->error == 1) // Je crois que si on suit avec une variable, nous allons free notre programme sans LEAKS. 
		//errmsg(ERR_MAP_WALLS, 1 , game);
}

void	verify_first_last_wall(t_game *game, int i)
{
	int j;

	j = 0;
	while (game->map_copy[i][j])
	{
		if (game->map_copy[i][j] != '1' && game->map_copy[i][j] != '-')
			errmsg(ERR_MAP_WALLS, 1, game);
		j++;
	}
}

void	verify_vertical_walls(t_game *game, int i)
{
	int j;

	j = 0;
	while (game->map_copy[i][j] == '-')
		j++;
	if (game->map_copy[i][j] != '1')
		errmsg(ERR_MAP_WALLS, 1, game);
	while (game->map_copy[i][j] != '-' && game->map_copy[i][j] != '\0')
		j++;
	if (game->map_copy[i][j - 1] != '1')
		errmsg(ERR_MAP_WALLS, 1, game);
}

void	verify_map_walls(t_game *game)
{
	int i;

	i = 0;
	while (game->map_copy[i])
	{
		if (i == 0 || i == (game->map_height - 1))
			verify_first_last_wall(game, i);
		else // Might not be necessary, because flood fill takes care of it. 
			verify_vertical_walls(game, i);
		i++;
	}
	verify_corner_walls(game);
}
