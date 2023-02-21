#include "../include/cub3d.h"

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
