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

void	bob_ross_line(t_game *g, int i, int side)
{
	int	color;
	int line;

	line = g->rc->draw_start - 1;
	if (side == 0)
		color = get_color(255, 0, 0, 255);
	else
		color = get_color(255, 255, 0, 255);
	while (++line <= g->rc->draw_end)
		mlx_put_pixel(g->game, i, line, color);
}
