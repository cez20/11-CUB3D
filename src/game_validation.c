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

void	game_full_copy(t_game *game, char *argv)
{
	char	*map_line;
	int		i;

	i = 0;
	map_line = NULL;
	game->full_map = ft_calloc((game->total_length + 1), sizeof(map_line));
	if (!game->full_map)
		return ;
	game->fd = open(argv, O_RDONLY);
	while (i < game->total_length)
	{
		map_line = get_next_line(game->fd);
		game->full_map[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
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
		str = get_next_line(game->fd);
	}
	close(game->fd); //When I finish reading a fd, does it close automatically?
	game->fd = 0;
}

void	game_copy(t_game *game, char *argv)
{
	game_length(game);
	game_full_copy(game, argv);
	//print_full_game(game);
}
