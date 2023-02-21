#include "../include/cub3d.h"

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

// void	verify_corner_walls(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (game->map_copy[i])
// 	{
// 		j = 0;
// 		while(game->map_copy[i][j])
// 		{
// 			if(game->map_copy[i][j] == '-')
// 				flood_fill(i, j, game);
// 			j++;
// 		}
// 		i++;
// 	}
// 	//print_game(game->map_copy);
// 	//if (game->error == 1) // Je crois que si on suit avec une variable, nous allons free notre programme sans LEAKS. 
// 		//errmsg(ERR_MAP_WALLS, 1 , game);
// }

// void	verify_first_last_wall(t_game *game, int i)
// {
// 	int j;

// 	j = 0;
// 	while (game->map_copy[i][j])
// 	{
// 		if (game->map_copy[i][j] != '1' && game->map_copy[i][j] != '-')
// 			errmsg(ERR_MAP_WALLS, 1, game);
// 		j++;
// 	}
// }

// void	verify_vertical_walls(t_game *game, int i)
// {
// 	int j;

// 	j = 0;
// 	while (game->map_copy[i][j] == '-')
// 		j++;
// 	if (game->map_copy[i][j] != '1')
// 		errmsg(ERR_MAP_WALLS, 1, game);
// 	while (game->map_copy[i][j] != '-' && game->map_copy[i][j] != '\0')
// 		j++;
// 	if (game->map_copy[i][j - 1] != '1')
// 		errmsg(ERR_MAP_WALLS, 1, game);
// }

// void	verify_map_walls(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while (game->map_copy[i])
// 	{
// 		if (i == 0 || i == (game->map_height - 1))
// 			verify_first_last_wall(game, i);
// 		else // Might not be necessary, because flood fill takes care of it. 
// 			verify_vertical_walls(game, i);
// 		i++;
// 	}
// 	verify_corner_walls(game);
// }

//My take on wall verification:
//I read the map left to right, top to bottom, checking certain conditions on zeroes only.
//First: If there are any 0's at the extremities: error;
//Else: If there are any spaces NOT surrounded by walls inside the map (holes filled with '-' character): error;
//This doesn't check for diagonals (though it could) because valid empty spaces would be filled with walls AFTER map validation, so that would prevent any bugs later on.
// Floodfill becomes useless at this point since we don't have to check for valid pathways, etc. (unless we decide later to add collectibles, etc)
void	verify_map_walls(t_game *game)
{
	int i;
	int j;
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
						|| game->map_copy[i - 1][j - 1] == '-' // The 4 next position start here.
						|| game->map_copy[i + 1][j - 1] == '-'
						|| game->map_copy[i - 1][j + 1] == '-'
						|| game->map_copy[i + 1][j + 1] == '-')
					errmsg(ERR_MAP_WALLS, 1, game);
			}
		}
	}
}
