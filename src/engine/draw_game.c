/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:10 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 16:25:48 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*There are no mistakes, just happy accidents... And segfaults.*/

#include "../include/cub3d.h"

void	floor_n_ceiling(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(g->game, i, j, g->rc->ceiling);
			else
				mlx_put_pixel(g->game, i, j, g->rc->floor);
		}
	}
}

void	draw_texture_ns(t_game *g, xpm_t *tex, int **tab, int i)
{
	double	step;
	double	tex_pos;
	int		line;

	step = 1.0 * tex->texture.height / g->rc->line_height;
	tex_pos = ((double) g->rc->draw_start - (double) HEIGHT / 2
			+ (double) g->rc->line_height / 2) * step;
	line = g->rc->draw_start - 1;
	while (++line < g->rc->draw_end)
	{
		g->tex->texture_y = (int)tex_pos;
		if (tex_pos > tex->texture.height - 1)
			tex_pos = tex->texture.height - 1;
		tex_pos += step;
		mlx_put_pixel(g->game, i, line, \
			((tab[g->tex->texture_y][g->tex->texture_x] >> 1) & 8355711));
	}
}

void	draw_texture_ew(t_game *g, xpm_t *tex, int **tab, int i)
{
	double	step;
	double	tex_pos;
	int		line;

	step = 1.0 * tex->texture.height / g->rc->line_height;
	tex_pos = ((double) g->rc->draw_start - (double) HEIGHT / 2
			+ (double) g->rc->line_height / 2) * step;
	line = g->rc->draw_start - 1;
	while (++line < g->rc->draw_end)
	{
		g->tex->texture_y = (int)tex_pos;
		if (tex_pos > tex->texture.height - 1)
			tex_pos = tex->texture.height - 1;
		tex_pos += step;
		mlx_put_pixel(g->game, i, line, \
			(tab[g->tex->texture_y][g->tex->texture_x]));
	}
}
