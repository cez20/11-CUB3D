#include "../include/cub3d.h"

void	init_variables(t_game *game)
{
	game->fd = 0;
	game->total_length = 0;
	game->game_copy = NULL;
	game->map_copy = NULL;
	game->elements_copy = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

void	close_fds(t_game *game)
{
	close(game->fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	init_variables(&game);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_NO_MAP);
	//print_variables(&game);
	game_valid_extension(argv[1], game.fd);
	game_copy(&game, argv[1]);
	free_double_pointer(game.game_copy);
	close_fds(&game);
	return (0);
}
