/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:26 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:38:27 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		rc->dir_x = -1;
		rc->dir_y = 0;
	}
	if (direction == 'W')
	{
		rc->dir_x = 1;
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
		rc->plane_y = -0.66;
	}
	if (direction == 'W')
	{
		rc->plane_x = 0;
		rc->plane_y = 0.66;
	}
}

int	init_mlx_variables(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	g->game = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (!g->game)
		return (-1);
	return (0);
}

void	init_dda_variables(t_game *g)
{
	g->rc->map = g->map_copy;
	g->rc->pos_x = g->player_y + 0.5;
	g->rc->pos_y = g->player_x + 0.5;
	g->rc->map_x = (int)g->rc->pos_x;
	g->rc->map_y = (int)g->rc->pos_y;
	set_direction(g->direction, g->rc);
	set_plane(g->direction, g->rc);
	g->rc->move_speed = 0.15;
	g->rc->rot_speed = 0.15;
	g->rc->floor = get_color(g->tex->floor[0], \
		g->tex->floor[1], g->tex->floor[2], 255);
	g->rc->ceiling = get_color(g->tex->ceiling[0], \
		g->tex->ceiling[1], g->tex->ceiling[2], 255);
}
