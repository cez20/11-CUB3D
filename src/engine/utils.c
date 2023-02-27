#include "../include/cub3d.h"

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

void	init_img_variables(t_game *g)
{
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
//	ft_memset(g->img->pixels, 255, WIDTH * HEIGHT * BPP);
	g->rc->hit = false;
	g->rc->line_height = 0;
	g->rc->draw_start = 0;
	g->rc->pos_x = g->player_x;
	g->rc->pos_y = g->player_y;
	set_direction(g->direction, g->rc);
	set_plane(g->direction, g->rc);
	g->rc->floor = get_color(g->tex->floor[0],\
		g->tex->floor[1], g->tex->floor[2], 255);
	g->rc->ceiling = get_color(g->tex->ceiling[0],\
		g->tex->ceiling[1], g->tex->ceiling[2], 255);
	//time? fps counter, etc
}
