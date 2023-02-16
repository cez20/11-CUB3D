#include "../include/cub3d.h"

void	verify_first_last_wall(t_game *game, int i)
{
	int j;

	j = 0;
	while (game->map_copy1[i][j])
	{
		if (game->map_copy1[i][j] != '1' && game->map_copy1[i][j] != '-')
			errmsg(ERR_MAP_WALLS, 1, game);
		j++;
	}
}

void	verify_vertical_walls(t_game *game, int i)
{
	int j;

	j = 0;
	while (game->map_copy1[i][j] == '-')
		j++;
	if (game->map_copy1[i][j] != '1')
		errmsg(ERR_MAP_WALLS, 1, game);
	while (game->map_copy1[i][j] != '-' && game->map_copy1[i][j] != '\0')
		j++;
	if (game->map_copy[i][j - 1] != '1')
		errmsg(ERR_MAP_WALLS, 1, game);
}

void	verify_map_extremities(t_game *game)
{
	int i;

	i = 0;
	while (game->map_copy1[i])
	{
		if (i == 0 && i == (game->height - 1))
			verify_first_last_wall(game, i);
		else
			verify_vertical_walls(game, i);
		i++;
	}
}

