#include "../include/cub3d.h"
static void free_tex(t_tex *tex)
{
	int i;

	i = 0;
	while (tex->n[i]){
		xfree(tex->n[i]);
		i++;
	}
	xfree(tex->n);
	i = 0;
	while (tex->s[i]){
		xfree(tex->s[i]);
		i++;
	}
	xfree(tex->s);
	i = 0;
	while (tex->w[i]){
		xfree(tex->w[i]);
		i++;
	}
	xfree(tex->w);
	i = 0;
	while (tex->e[i]){
		xfree(tex->e[i]);
		i++;
	}
	xfree(tex->e);
}

void	mlx_end(t_game *g)
{
	if (g->game)
		mlx_delete_image(g->mlx, g->game);
	// if (g->minimap)
	// 	mlx_delete_image(g->mlx, g->minimap);
	free_tex(g->tex);
	if (g->tex->no)
		mlx_delete_xpm42(g->tex->no);
	if (g->tex->so)
		mlx_delete_xpm42(g->tex->so);
	if (g->tex->ea)
		mlx_delete_xpm42(g->tex->ea);
	if (g->tex->we)
		mlx_delete_xpm42(g->tex->we);
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
