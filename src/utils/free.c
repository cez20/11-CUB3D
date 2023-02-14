#include "../include/cub3d.h"

void	free_game(t_game *game)
{
	free_double_pointer(game->game_copy);
	free_double_pointer(game->elements_copy);
	game->map_copy = NULL; // Avoid a dangling pointer
}

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
