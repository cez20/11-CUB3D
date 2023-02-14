#include "../include/cub3d.h"

void	game_map_copy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->game_copy[i])
	{
		if (game->game_copy[i][j] == '1' || game->game_copy[i][j] == '0')
			break ;
		i++;
	}
	game->map_index = i;
	game->map_copy = &game->game_copy[i];
	game->height = game->total_length - game->map_index;
}

void	game_elements_copy(t_game *game)
{
	int	i;

	i = 0;
	game->elements_copy = ft_calloc(game->map_index + 1, sizeof(char *));
	while (i < game->map_index)
	{
		game->elements_copy[i] = ft_strdup(game->game_copy[i]);
		i++;
	}
	//print_game(game->elements_copy);
}

void	game_full_copy(t_game *game, char *argv)
{
	char	*map_line;
	int		i;

	i = 0;
	map_line = NULL;
	game->game_copy = ft_calloc((game->total_length + 1), sizeof(map_line));
	if (!game->game_copy)
		return ;
	game->fd = open(argv, O_RDONLY);
	while (i < game->total_length)
	{
		map_line = get_next_line(game->fd);
		game->game_copy[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
	}
}

void	game_length(t_game *game)
{
	char	*str;

	str = get_next_line(game->fd);
	if (!str)
		errmsg(ERR_EMPTY_MAP, 1, game);
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
	game_map_copy(game);
	game_elements_copy(game);
	// print_game(game->game_copy);
	// print_game(game->elements_copy);
	// print_game(game->map_copy);
}
