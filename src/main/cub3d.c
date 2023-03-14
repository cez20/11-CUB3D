#include "../include/cub3d.h"

void	keybinding(mlx_key_data_t input, void *tmp)
{
	t_game	*g;

	g = tmp;
	if (input.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	if (input.key == MLX_KEY_RIGHT)
		look_right(g->rc);
	if (input.key == MLX_KEY_LEFT)
		look_left(g->rc);
	if (input.key == MLX_KEY_A)
		strafe(g->rc, 'L');
	if (input.key == MLX_KEY_D)
		strafe(g->rc, 'R');
	if (input.key == MLX_KEY_W)
		forward(g->rc);
	if (input.key == MLX_KEY_S)
		backward(g->rc);
	g->player_x = g->rc->pos_x;
	g->player_y = g->rc->pos_y;
	raycaster(g);
}

void	rendering(void *tmp)
{
	t_game	*g;

	g = tmp;
	mlx_key_hook(g->mlx, &keybinding, g);
	raycaster(g);
	mlx_image_to_window(g->mlx, g->game, 0, 0);
}

int	cub3d(t_game *g)
{
	if (init_mlx_variables(g) != 0)
		errmsg("Error: MLX failed.\n", 1, g);
	init_dda_variables(g);
	load_and_convert_textures(g);
	raycaster(g);
	// mlx_image_to_window(g->mlx, g->game, 0, 0);
	mlx_key_hook(g->mlx, &keybinding, g);
//	mlx_loop_hook(g->mlx, &rendering, g);
//	mlx_cursor_hook(); // optional (bonus)
	mlx_loop(g->mlx);
	return (0);
}
