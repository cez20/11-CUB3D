#include "../include/cub3d.h"

void print_ddavariables (t_game *game)
{
	printf("hit [ %d ] side [ %c ]\n", game->rc->hit, game->rc->side);
	printf("pos_x [ %f ] pos_y [ %f ]\n", game->rc->pos_x, game->rc->pos_y);
	printf("dir_x [ %f ] dir_y [ %f ]\n", game->rc->dir_x, game->rc->dir_y);
	printf("plane_x [ %f ] plane_y [ %f ]\n\n", game->rc->plane_x, game->rc->plane_y);
}
// TODO:
	// load xpm
	//	g->tex->no = mlx_load_xpm42(g->tex->north);
	// if (!g->tex->no)
	// 	errmsg("Load XPM fail.\n", 1, g);

	// code dda/raycaster
	// code keyhooks modifiers
	// draw image
	// put image to window
	// rinse repeat
// MY INPUT ARE WRONG, THE DIRECTION VECTOR IS NOT WELL SET! OR IS IT MY MOVEMENT?
// FINISH RAYCASTER AND SEE.

// This function is for events, everytime a key is pressed, we move the player position of 0.2
// to the left, to the right, up or down.To make sure that map is updated in real time,
// we call back the function draw _background, draw_map, and draw_player. If these functions,
// were not called, there would'nt be any change between first map and other maps. 
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
	rendering(g);
}

void	rendering(void *tmp)
{
	t_game	*g;

	g = tmp;
	mlx_key_hook(g->mlx, &keybinding, g); 
	print_ddavariables(g);
	// draw_background(g); // This is the background color
	// draw_map(g);
	// draw_player(g, (g->rc->pos_x) * 64, (g->rc->pos_y) * 64, get_color(255, 0, 0, 255));
	raycaster(g);
	mlx_image_to_window(g->mlx, g->game, 0, 0);
}

int	cub3d(t_game *g)
{
	if (init_mlx_variables(g) != 0)
		errmsg("Error: MLX failed.\n", 1, g);
	init_dda_variables(g);
	rendering(g);
	mlx_loop_hook(g->mlx, &rendering, g);
//	mlx_cursor_hook(); // optional (bonus)
	mlx_loop(g->mlx);
	return (0);
}
