#include "../include/cub3d.h"

/* This function's goal is to calculate ray position and direction
If ray_dir_x of ray_dir_y are 0, the division through zero is avoided by
setting it to a very high value (1e30: an arbitrarily chosen high enough number)
interpreted as infinity */

static void set_ray_posdir(t_game *g, double x)
{
	g->rc->camera_x = 2 * x / (double)(g->map_width * 64) - 1;
	g->rc->ray_dir_x = g->rc->dir_x + g->rc->plane_x * g->rc->camera_x;
	g->rc->ray_dir_y = g->rc->dir_y + g->rc->plane_y * g->rc->camera_x;
	g->rc->map_x = g->rc->pos_x;
	g->rc->map_y = g->rc->pos_y;
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
		rc->side_dis_x = (rc->map_x + 1 - rc->pos_x) * rc->delta_dis_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dis_y = (rc->pos_y = rc->map_y) * rc->delta_dis_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dis_y = (rc->map_y + 1 - rc->pos_y) * rc->delta_dis_y;
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
		if (rc->map[rc->map_x][rc->map_y] == '1')
			rc->hit = 1;
	}
}

void	raycaster(t_game *g)
{
	int	i;

	i = -1;
	//something to clear ?
	while (++i < g->map_width * 64)
	{
		set_ray_posdir(g, i);
		set_step(g->rc);
		dda_time(g->rc);
//		get_draw_len(g, i);
//		bob_ross(g, i);
//		i++;
	}
}
