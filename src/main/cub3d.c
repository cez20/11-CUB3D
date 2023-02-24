#include "../include/cub3d.h"

int	cub3d(t_game *g)
{
	mlx_image_t *img;
	img = NULL;
	g->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	// load xpm
	// code dda/raycaster
	// draw image
	// put image to window
	// rinse repeat
	g->tex->no =  mlx_load_xpm42(g->tex->north);
	if (!g->tex->no)
		errmsg("Load XPM fail.\n", 1, g);
	img = mlx_texture_to_image(g->mlx, &g->tex->no->texture);
	mlx_image_to_window(g->mlx, img, 0, 0);
	mlx_loop(g->mlx);
//	mlx_terminate(g->mlx);
//	free_game(g);
	return (0);
}
