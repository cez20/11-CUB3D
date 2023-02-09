#include "../include/cub3d.h"


void	map_valid_extension(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_NO_MAP);
	map_valid_extension(argv[1], game.fd);
	return (0);
}