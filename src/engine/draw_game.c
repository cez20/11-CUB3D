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

// void	bob_ross_line(t_game *g, int i, int side)
// {
// 	int	color;
// 	int	line;

// 	line = g->rc->draw_start - 1;
// 	if (side == 0)
// 		color = get_color(255, 0, 0, 255);
// 	else
// 		color = get_color(255, 255, 0, 255);
// 	while (++line <= g->rc->draw_end)
// 		mlx_put_pixel(g->game, i, line, color);
// }

void	draw_texture_line(t_game *g, xpm_t *tex, int **tab, int i)
{
	double step;
	double tex_pos;
	int line;

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
		mlx_put_pixel(g->game, i, line, tab[g->tex->texture_y][g->tex->texture_x]);
	}
}

//First version to draw textures 
// void	bob_ross_line2(t_game *g, int i, int side)
// {
// 	int	color;
// 	int	line;
// 	(void)side;
// 	(void)color;

// 	line = g->rc->draw_start - 1;
// 	g->tex->texture_y = 0;
// 	//if (side == 0)
// 		//color = get_color(255, 0, 0, 255);
// 	//else
// 		//color = get_color(255, 255, 0, 255);
// 	while (++line <= g->rc->draw_end)
// 		mlx_put_pixel(g->game, i, line, g->tex->n[g->tex->texture_x][g->tex->texture_y]);
// }