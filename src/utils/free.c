#include "../include/cub3d.h"

void	mlx_end(t_game *g)
{
	if (g->game)
		mlx_delete_image(g->mlx, g->game);
	if (g->minimap)
		mlx_delete_image(g->mlx, g->minimap);
	if (g->mlx)
		mlx_terminate(g->mlx);
}

void	free_game(t_game *game)
{
	free_double_pointer(game->game_copy);
	free_double_pointer(game->elements_copy);
	free_double_pointer(game->map_copy);
	xfree(game->tex->north);
	xfree(game->tex->south);
	xfree(game->tex->east);
	xfree(game->tex->west);
	xfree(game->tex);
	xfree(game->rc);
	if (game->mlx)
		mlx_end(game);
}

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		xfree(str[i++]);
	xfree(str);
}
