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
}

//My take on wall verification:
//I read the map left to right, top to bottom, 
//checking certain conditions on zeroes only.
//First: If there are any 0's at the extremities: error;
//Else: If there are any spaces NOT surrounded by walls inside 
void	verify_map_walls(t_game *game)
{
	int	i;
	int	j;

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
					errmsg(ERR_INTEGRITY, 1, game);
				else if (game->map_copy[i - 1][j] == '-'
						|| game->map_copy[i + 1][j] == '-'
						|| game->map_copy[i][j + 1] == '-'
						|| game->map_copy[i][j - 1] == '-'
						|| game->map_copy[i - 1][j - 1] == '-'
						|| game->map_copy[i - 1][j + 1] == '-'
						|| game->map_copy[i + 1][j + 1] == '-')
					errmsg(ERR_INTEGRITY, 1, game);
			}
		}
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
				errmsg(ERR_CHAR, 1, g);
			j++;
		}
		i++;
	}
	if (g->nb_player < 1 || g->nb_player > 1)
		errmsg(ERR_PLAYER, 1, g);
}
