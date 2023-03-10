/**There are no mistakes, just happy accidents... And segfaults.*/

#include "../include/cub3d.h"

/* This function's goal is to calculate ray position and direction
If ray_dir_x of ray_dir_y are 0, the division through zero is avoided by
setting it to a very high value (1e30: an arbitrarily chosen high enough number)
interpreted as infinity */
void	set_ray_posdir(t_game *g, double i)
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

/* "The DDA algorithm will always jump exactly one square each loop,
either a square in the x-direction, or a square in the y-direction.
If it has to go in the negative or positive x-direction, 
and the negative or positive y-direction will depend on the ray's direction, 
and this fact will be stored in stepX and stepY.
Those variables are always either -1 or +1." 
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

// void	set_line_len(t_game *g)
// {
// 	int		line_height;
// 	double	intersect_dist; // distance to the wall

// 	if (g->rc->side == 0)
// 		intersect_dist = g->rc->side_dis_x - g->rc->delta_dis_x;
// 	else
// 		intersect_dist = g->rc->side_dis_y - g->rc->delta_dis_y;
// 	line_height = HEIGHT / intersect_dist; //ratio to adapt the line height to the screen height
// 	g->rc->draw_start = (-line_height / 2) + (HEIGHT / 2);
// 	if (g->rc->draw_start < 0)
// 		g->rc->draw_start = 0;
// 	g->rc->draw_end = (line_height / 2) + (HEIGHT / 2);
// 	if (g->rc->draw_end >= HEIGHT)
// 		g->rc->draw_end = HEIGHT - 1;
// }

void	set_line_len(t_game *g)
{
	if (g->rc->side == 0)
		g->rc->intersect_dist = g->rc->side_dis_x - g->rc->delta_dis_x;
	else
		g->rc->intersect_dist = g->rc->side_dis_y - g->rc->delta_dis_y;
	g->rc->line_height = (int)(HEIGHT / g->rc->intersect_dist);
	g->rc->draw_start = -g->rc->line_height / 2 + HEIGHT / 2;
	if (g->rc->draw_start < 0)
		g->rc->draw_start = 0;
	g->rc->draw_end = g->rc->line_height / 2 + HEIGHT / 2;
	if (g->rc->draw_end >= HEIGHT)
		g->rc->draw_end = HEIGHT;
}
