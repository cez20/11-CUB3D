/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:17 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 16:26:11 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*There are no mistakes, just happy accidents... And segfaults.*/

#include "../include/cub3d.h"

/* This function's goal is to calculate ray position and direction
If ray_dir_x of ray_dir_y are 0, the division through zero is avoided by
setting it to a very high value (1e30: an arbitrarily chosen high enough number)
interpreted as infinity */
static void	set_ray_posdir(t_game *g, double i)
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
static void	set_step(t_ray *rc)
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

static void	dda_time(t_ray *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dis_x < rc->side_dis_y)
		{
			rc->side_dis_x += rc->delta_dis_x;
			rc->map_x += rc->step_x;
			if (rc->ray_dir_x > 0)
				rc->side = EAST;
			else
				rc->side = WEST;
		}
		else
		{
			rc->side_dis_y += rc->delta_dis_y;
			rc->map_y += rc->step_y;
			if (rc->ray_dir_y > 0)
				rc->side = SOUTH;
			else
				rc->side = NORTH;
		}
		if (rc->map[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;
	}
}

static void	set_line_len(t_game *g)
{
	if (g->rc->side == 0 || g->rc->side == 1)
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

/* This function starts by projecting ceiling and floor all over
Then, while loop goes thrugh every 'i' is a slice in the screen
We calculateray position and direction and determines which
axis is first hit and we calculate the distance to a wall (collision)
We calculate size of line to be drawn and draw it on scree. */
void	raycaster(t_game *g)
{
	int	i;

	i = -1;
	g->player_x = g->rc->pos_x;
	g->player_y = g->rc->pos_y;
	floor_n_ceiling(g);
	while (++i < WIDTH)
	{
		g->rc->hit = 0;
		set_ray_posdir(g, i);
		set_step(g->rc);
		dda_time(g->rc);
		set_line_len(g);
		texture_calculation(g);
		if (g->rc->side == EAST)
			draw_texture_ew(g, g->tex->ea, g->tex->e, i);
		else if (g->rc->side == WEST)
			draw_texture_ew(g, g->tex->we, g->tex->w, i);
		else if (g->rc->side == SOUTH)
			draw_texture_ns(g, g->tex->so, g->tex->s, i);
		else
			draw_texture_ns(g, g->tex->no, g->tex->n, i);
	}
	mlx_image_to_window(g->mlx, g->game, 0, 0);
}
