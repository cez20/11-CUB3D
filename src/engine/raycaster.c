/*There are no mistakes, just happy accidents... And segfaults.*/

#include "../include/cub3d.h"

static void	floor_n_ceiling (t_game *g)
{
	int	i;
	int	j;
	uint32_t	c_color;
	uint32_t	f_color;

	i = -1;
	c_color = get_color(g->tex->ceiling[0], g->tex->ceiling[1], g->tex->ceiling[2], 255);
	f_color = get_color(g->tex->floor[0], g->tex->floor[1], g->tex->floor[2], 255);
	while (++i < WIDTH - 1)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (j < HEIGHT/2)
				mlx_put_pixel(g->game, i, j, c_color);
			else
				mlx_put_pixel(g->game, i, j, f_color);
		}
	}
}

static void	bob_ross_line (t_game *g, double i, int side)
{
	int	color;

	if (side == 0)
		color = get_color(255, 0, 0, 255);
	else
	 	color = get_color(255, 255, 0, 255);
	g->rc->draw_start -= 1;
	while (++g->rc->draw_start < g->rc->draw_end)
		mlx_put_pixel(g->game, (int)i, g->rc->draw_start, color);
}

static void set_line_len (t_game *g)
{
	double	intersect_dist;
	int		line_height;

	if (g->rc->side == 0)
		intersect_dist = g->rc->side_dis_x - g->rc->delta_dis_x;
	else
		intersect_dist = g->rc->side_dis_y - g->rc->delta_dis_y;
	line_height = HEIGHT / intersect_dist;

	g->rc->draw_start = (-line_height / 2) + (HEIGHT / 2);
	if (g->rc->draw_start < 0)
		g->rc->draw_start = 0;
	g->rc->draw_end = (line_height / 2) + (HEIGHT / 2);
	if (g->rc->draw_end >= HEIGHT)
		g->rc->draw_end = HEIGHT - 1;
}

/* This function's goal is to calculate ray position and direction
If ray_dir_x of ray_dir_y are 0, the division through zero is avoided by
setting it to a very high value (1e30: an arbitrarily chosen high enough number)
interpreted as infinity */

static void set_ray_posdir(t_game *g, double i)
{
	g->rc->camera_x = 2 * i / (double) WIDTH - 1;
	g->rc->ray_dir_x = g->rc->dir_x + g->rc->plane_x * g->rc->camera_x;
	g->rc->ray_dir_y = g->rc->dir_y + g->rc->plane_y * g->rc->camera_x;
	g->rc->map_x = (int)g->rc->pos_x;
	g->rc->map_y = (int)g->rc->pos_y;
	if (g->rc->ray_dir_x == 0)
		g->rc->delta_dis_x = 1e30;
	else
		g->rc->delta_dis_x = fabs(1 / g->rc->ray_dir_x);
	if (g->rc->ray_dir_y == 0)
		g->rc->delta_dis_y = 1e30;
	else
		g->rc->delta_dis_y = fabs(1 / g->rc->ray_dir_y);
}

/* "The DDA algorithm will always jump exactly one square each loop, either a square in the x-direction,
or a square in the y-direction. If it has to go in the negative or positive x-direction, 
and the negative or positive y-direction will depend on the direction of the ray, 
and this fact will be stored in stepX and stepY. Those variables are always either -1 or +1." 
(Ref.: Lodev.org)*/
void	set_step(t_ray *rc)
{

	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dis_x = (rc->pos_x - rc->map_x) * rc->delta_dis_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dis_x = (rc->map_x + 1.0 - rc->pos_x) * rc->delta_dis_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dis_y = (rc->pos_y - rc->map_y) * rc->delta_dis_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dis_y = (rc->map_y + 1.0 - rc->pos_y) * rc->delta_dis_y;
	}
}

void	dda_time(t_ray *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dis_x < rc->side_dis_y)
		{
			rc->side_dis_x += rc->delta_dis_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dis_y += rc->delta_dis_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;			
	}
	//Below calculated distance between camera_plane and hitpoint to avoid
	// fish eye effect 
	if (rc->side == 0)
		rc->perp_wall_distance = rc->side_dis_x - rc->delta_dis_x;
	else
		rc->perp_wall_distance = rc->side_dis_y - rc->delta_dis_y;
}

void	get_draw_len(t_game *g,  int i)
{
	(void)i;
	g->rc->line_height = HEIGHT/ g->rc->perp_wall_distance;
	g->rc->draw_start = -g->rc->line_height / 2 + HEIGHT / 2;
	if (g->rc->draw_start < 0)
		g->rc->draw_start  = 0;
	g->rc->draw_end = g->rc->line_height / 2 +  HEIGHT / 2;
	if (g->rc->draw_end >= HEIGHT)
		g->rc->draw_end = HEIGHT;
}

void	raycaster(t_game *g)
{
	int	i;

	i = -1;
	floor_n_ceiling(g);
	while (++i < WIDTH)
	{
		g->rc->hit = 0;
		g->rc->side = 0;
		set_ray_posdir(g, i);
		set_step(g->rc);
		dda_time(g->rc);
		set_line_len(g);
		// if ((int)i % 320 == 0 || i ==480 || i == 959)
		// 	printf("\t[%d]\tcameraX = %f / raydirX = %f / raydirY = %f / deltadistX = %f / deltadisY = %f / sidedisX = %f / sidedisY = %f\n", (int)i, g->rc->camera_x, g->rc->ray_dir_x, g->rc->ray_dir_y, g->rc->delta_dis_x, g->rc->delta_dis_y, g->rc->side_dis_x, g->rc->side_dis_y);
		bob_ross_line(g, i, g->rc->side);
	}
}
