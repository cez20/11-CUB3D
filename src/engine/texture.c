/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:22 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:38:23 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//This function convert the texture into an 2D array of int
//Each set of 4 pixels of the textures represents a RGBA color
// First = R , Second = G, Third = G, Fourth = A
static int	**convert_texture_to_color_array(xpm_t *image)
{
	int	**tab;
	int	count;
	int	i;
	int	j;

	tab = ft_calloc(sizeof(int *), image->texture.height + 1);
	count = 0;
	i = -1;
	while (++i < (int)image->texture.height)
	{	
		tab[i] = ft_calloc(sizeof(int), image->texture.width);
		j = -1;
		while (++j < (int)image->texture.width)
		{
			tab[i][j] = get_color(
					image->texture.pixels[count + 0],
					image->texture.pixels[count + 1],
					image->texture.pixels[count + 2],
					image->texture.pixels[count + 3]);
			count += 4;
		}
	}
	return (tab);
}

void	texture_calculation(t_game *g)
{
	double	wall_x_hit;
	double	tex_width;

	g->tex->texture_num = g->rc->map[g->rc->map_y][g->rc->map_x] - 1;
	tex_width = (double)g->tex->no->texture.width;
	if (g->rc->side == EAST || g->rc->side == WEST)
		wall_x_hit = g->rc->pos_y + g->rc->intersect_dist * g->rc->ray_dir_y;
	else
		wall_x_hit = g->rc->pos_x + g->rc->intersect_dist * g->rc->ray_dir_x;
	wall_x_hit -= floor((wall_x_hit));
	g->tex->texture_x = (int)(wall_x_hit * tex_width);
	if ((g->rc->side == EAST || g->rc->side == WEST) && g->rc->ray_dir_x > 0)
		g->tex->texture_x = tex_width - g->tex->texture_x - 1;
	if ((g->rc->side == SOUTH || g->rc->side == NORTH) && g->rc->ray_dir_y < 0)
		g->tex->texture_x = tex_width - g->tex->texture_x - 1;
}

//This function first load a texture image into a xpm42 format
//Then it converts the xpm42 texture image into a 2D array of int
// that each represent a color of the texture
void	load_and_convert_textures(t_game *g)
{
	g->tex->no = mlx_load_xpm42(g->tex->north);
	if (!g->tex->no)
		errmsg(ERR_XPM42, 1, g);
	g->tex->so = mlx_load_xpm42(g->tex->south);
	if (!g->tex->so)
		errmsg(ERR_XPM42, 1, g);
	g->tex->we = mlx_load_xpm42(g->tex->west);
	if (!g->tex->we)
		errmsg(ERR_XPM42, 1, g);
	g->tex->ea = mlx_load_xpm42(g->tex->east);
	if (!g->tex->ea)
		errmsg(ERR_XPM42, 1, g);
	g->tex->n = convert_texture_to_color_array(g->tex->no);
	g->tex->s = convert_texture_to_color_array(g->tex->so);
	g->tex->e = convert_texture_to_color_array(g->tex->ea);
	g->tex->w = convert_texture_to_color_array(g->tex->we);
}
