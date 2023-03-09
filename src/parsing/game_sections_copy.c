#include "../include/cub3d.h"

void	game_map_copy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map_index;
	game->map_copy = ft_calloc((game->map_height + 1), sizeof(char *));
	while (i < game->map_height)
	{
		game->map_copy[i] = ft_calloc(game->map_width + 1, sizeof(char));
		ft_strlcpy1(game->map_copy[i], game->game_copy[j], game->map_width + 1);
		i++;
		j++;
	}
}

void	game_elements_copy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->elements_copy = ft_calloc(game->map_index + 1, sizeof(char *));
	while (i < game->map_index)
	{
		if (ft_isspace(game->game_copy[i]) == 0)
			i++;
		else
			game->elements_copy[j++] = ft_strdup(game->game_copy[i++]);
	}
}

void	game_map_dimensions(t_game *game)
{
	game->map_index = map_first_index(game->game_copy);
	game->map_height = game->total_length - game->map_index;
	game->map_width = map_longest_width(game);
}

void	game_full_copy(t_game *game, char *argv)
{
	char	*map_line;
	int		i;

	i = 0;
	map_line = NULL;
	game->fd = open(argv, O_RDONLY);
	game->game_copy = ft_calloc((game->total_length + 1), sizeof(map_line));
	while (i < game->total_length)
	{
		map_line = get_next_line(game->fd);
		game->game_copy[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
	}
}

void	game_sections_copy(t_game *game, char *argv)
{
	game_length(game);
	game_full_copy(game, argv);
	game_map_dimensions(game);
	game_elements_copy(game);
	game_map_copy(game);
}
