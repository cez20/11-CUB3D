#include "../include/cub3d.h"

void	game_valid_extension(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (str == NULL || ft_strncmp(str, ".cub", 5) != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
}

void	game_length(t_game *game)
{
	char	*str;

	str = get_next_line(game->fd);
	if (!str)
		error(ERR_EMPTY_MAP);
	while (1)
	{
		if (!str)
			break ;
		game->total_length++;
		free(str);
		str = NULL;
		str = get_next_line(game->fd);
	}
}

void	game_copy(t_game *game)
{
	game_length(game);
}
