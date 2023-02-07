#include "../include/cub3d.h"

static int	clean_exit (t_game *game)
{
	//check game->mlx, game->window
	free_table(game->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_FD);
	//map_valid_extension(argv[1], game.fd);
	map_to_table(game.fd, &game);
	return (clean_exit(&game));
}
