#include "../include/cub3d.h"

// TODO:
	// load xpm
	//	g->tex->no = mlx_load_xpm42(g->tex->north);
	// if (!g->tex->no)
	// 	errmsg("Load XPM fail.\n", 1, g);

	// code dda/raycaster
	// keyhooks
	// draw image
	// put image to window
	// rinse repeat

void keybinding(mlx_key_data_t input, void *tmp)
{
	t_game *g;
	g = tmp;

	if (input.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	if (input.key == MLX_KEY_RIGHT)
		printf("rotate();\n");
	if (input.key == MLX_KEY_LEFT)
		printf("rotate();\n");
	if (input.key == MLX_KEY_UP)
		printf("foward();\n");
	if (input.key == MLX_KEY_DOWN)
		printf("backward();\n");
}

static void	set_direction(char direction, t_ray *rc)
{
	if (direction == 'N')
	{
		rc->dir_x = 0;
		rc->dir_y = -1;
	}
	if (direction == 'S')
	{
		rc->dir_x = 0;
		rc->dir_y = 1;
	}
	if (direction == 'E')
	{
		rc->dir_x = 1;
		rc->dir_y = 0;
	}
	if (direction == 'W')
	{
		rc->dir_x = -1;
		rc->dir_y = 0;
	}
}

static void	set_plane(char direction, t_ray *rc)
{
	if (direction == 'N')
	{
		rc->plane_x = 0.66;
		rc->plane_y = 0;
	}
	if (direction == 'S')
	{
		rc->plane_x = -0.66;
		rc->plane_y = 0;
	}
	if (direction == 'E')
	{
		rc->plane_x = 0;
		rc->plane_y = 0.66;
	}
	if (direction == 'W')
	{
		rc->plane_x = 0;
		rc->plane_y = -0.66;
	}
}
static void	init_raycastvar(t_game *g)
{
	g->rc->pos_x = g->player_x;
	g->rc->pos_y = g->player_y;
	set_direction(g->direction, g->rc);
	set_plane(g->direction, g->rc);
	//time? fps counter, etc
}

int	cub3d(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	init_raycastvar(g);
	print_variables(g);
//	rendering(g); //raycaster math
	mlx_key_hook(g->mlx, &keybinding, g); //duplicating?
//	mlx_cursor_hook();
	mlx_loop(g->mlx);
//	mlx_terminate();
	return (0);
}
