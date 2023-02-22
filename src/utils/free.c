#include "../include/cub3d.h"

void	free_game(t_game *game)
{
	free_double_pointer(game->game_copy);
	free_double_pointer(game->elements_copy);
	free_double_pointer(game->map_copy);
	//destroy mlx instances, images and window
	xfree(game->tex->north);
	xfree(game->tex->south);
	xfree(game->tex->east);
	xfree(game->tex->west);
	xfree(game->tex);
	xfree(game->rc);
}

void	free_double_pointer(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
		xfree(str[i++]);
	xfree(str);
}
