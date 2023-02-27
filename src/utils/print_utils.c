#include "../include/cub3d.h"

void	print_variables(t_game *game)
{
	printf("The value of game->fd is %d\n", game->fd);
	printf("The value of game->total_length is %d\n", game->total_length);
	printf("The value of game->map_index is %d\n", game->map_index);
	printf("The value of game->game_copy is %p\n", game->game_copy);
	printf("The value of game->map_copy is %p\n", game->map_copy);
	printf("The value of map_width and map_hegiht are: map[%d][%d]\n", game->map_width, game->map_height);
	printf("The value of game->elements_copy is %p\n", game->elements_copy);
	printf("The value of game->mlx is %p\n", game->mlx);
	printf("TEXTURE'S PATHS\n");
	printf("NO [ %s ]\n", game->tex->north);
	printf("SO [ %s ]\n", game->tex->south);
	printf("EA [ %s ]\n", game->tex->east);
	printf("WE [ %s ]\n", game->tex->west);
	printf("COLORS\n");
	printf("Floor [ %d, %d, %d ]\n", game->tex->floor[0], game->tex->floor[1], game->tex->floor[2]);
	printf("Ceiling [ %d, %d, %d ]\n", game->tex->ceiling[0], game->tex->ceiling[1], game->tex->ceiling[2]);
	printf("RAYCASTING STRUCTURE\n");
	printf("Direction [ %c ]\n", game->direction);
	printf("pos_x [ %f ]\n", game->rc->pos_x);
	printf("pos_y [ %f ]\n", game->rc->pos_y);
	printf("dir_x [ %f ]\n", game->rc->dir_x);
	printf("dir_y [ %f ]\n", game->rc->dir_y);
	printf("plane_x [ %f ]\n", game->rc->plane_x);
	printf("plane_y [ %f ]\n", game->rc->plane_y);
	printf("Floor [ %i ]\n", game->rc->floor);
	printf("Ceiling [ %i ]\n", game->rc->ceiling);
}

void	print_game(char **str)
{
	int	i;

	i = 0;
	printf("--------DIVISION HERE----------\n");
	while (str[i])
		printf("%s\n", str[i++]);
}
