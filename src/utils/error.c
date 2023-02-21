#include "../include/cub3d.h"

void	errmsg(char *msg, int tofree, t_game *game)
{
	if (tofree == 1)
	{
		free_table(game->game_copy);
		free_table(game->elements_copy);
		free_table(game->map_copy);
	}
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

// void	error(char *str)
// {
// 	write(2, "Error\n", 6);
// 	write(2, str, ft_strlen(str));
// 	exit(EXIT_FAILURE);
// }
