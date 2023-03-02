#include "../include/cub3d.h"

static void	set_direction(char direction, t_ray *rc)
{
	if (direction == 'N')
	{
		rc->dir_x = 0;
		rc->dir_y = -1;
		rc->angle = (3 * M_PI) / 2;
	}
	if (direction == 'S')
	{
		rc->dir_x = 0;
		rc->dir_y = 1;
		rc->angle = M_PI / 2;
	}
	if (direction == 'E')
	{
		rc->dir_x = 1;
		rc->dir_y = 0;
		rc->angle = 2 * M_PI;
	}
	if (direction == 'W')
	{
		rc->dir_x = -1;
		rc->dir_y = 0;
		rc->angle = M_PI;
	}
}

static void	set_plane(char direction, t_ray *rc)
{
	if (direction == 'N')
	{
		rc->plane_x = 0;
		rc->plane_y = 0.66;
	}
	if (direction == 'S')
	{
		rc->plane_x = 0;
		rc->plane_y = -0.66;
	}
	if (direction == 'E')
	{
		rc->plane_x = 0.66;
		rc->plane_y = 0;
	}
	if (direction == 'W')
	{
		rc->plane_x = -0.66;
		rc->plane_y = 0;
	}
}

int	init_mlx_variables(t_game *g)
{
	g->mlx = mlx_init(g->map_width * 64, g->map_height * 64, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	g->minimap = mlx_new_image(g->mlx, g->map_width * 64, g->map_height * 64);
	if (!g->minimap)
		return (-1);
	g->game = mlx_new_image(g->mlx, g->map_width * 64, g->map_height * 64);
	if (!g->game)
		return (-1);
	return (0);
}

void	init_dda_variables(t_game *g)
{
	g->rc->hit = 0;
	g->rc->line_height = 0;
	g->rc->draw_start = 0;
	g->rc->map = g->map_copy;
	g->rc->step_x = 0;
	g->rc->step_y = 0;
	g->rc->pos_x = g->player_x; // position vector of the player
	g->rc->pos_y = g->player_y; // position vector of the player
	set_direction(g->direction, g->rc); // direction modifier
	set_plane(g->direction, g->rc);  // plane modifier
	g->rc->ray_dir_x = 0;
	g->rc->ray_dir_y = 0;
	g->rc->camera_x = 0;
	g->rc->move_speed = 0.2;
	g->rc->rot_speed = 0.2;
	g->rc->old_x = 0;
	g->rc->floor = get_color(g->tex->floor[0], \
		g->tex->floor[1], g->tex->floor[2], 255);
	g->rc->ceiling = get_color(g->tex->ceiling[0], \
		g->tex->ceiling[1], g->tex->ceiling[2], 255);
	//time? fps counter, etc
}
