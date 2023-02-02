#include "../include/cub3d.h"

void	errmsg(char *msg, int tofree, t_game *game)
{
	if (tofree == 1)
		free_table(game->map_copy);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
