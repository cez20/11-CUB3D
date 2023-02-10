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
			break;
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

// void	game_content_validation(t_game *game)
// {
// 	game_length(game);

	
// }

//Ceci est la fonction originale
// void	map_content_validation(int map_fd)
// {
// 	char	*map_line;

// 	map_line = get_next_line(map_fd);
// 	if (!map_line)
// 		error (ERR_EMPTY_MAP);
// }