#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_FD);
	//map_valid_extension(argv[1], game.fd);
	return (0);
}