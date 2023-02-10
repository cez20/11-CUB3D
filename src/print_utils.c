#include "../include/cub3d.h"

void	print_variables(t_game *game)
{
	printf("The value of game->fd is %d\n", game->fd);
	printf("The value of game->number_of_lines is %d\n", game->total_length);
	printf("The value of game->full_map is %p\n", game->full_map);
	printf("The value of game->mlx is %s\n", game->mlx);
	printf("The value of game->window is %s\n", game->window);
}
