#include "../include/cub3d.h"

int	cub3d(t_game *g)
{

	g->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!g->mlx)
		return (-1);
	printf("Coucou\n");
	return (0);
}