#include "../include/cub3d.h"

void print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

static	int count_lines(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map && !map[i])
	{
		xfree(map);
		errmsg(ERR_EMPTY_MAP, 1, game);
	}
	while (map[i])
		i++;
	return (i);
}

static int	count_max_row (char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while(map[i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = (int)ft_strlen(map[i]);
		i++;
	}
	return (max);
}

static void	set_dimensions(t_game *game)
{
	game->height = count_lines(game->map_copy, game);
	game->width = count_max_row(game->map_copy);
}

void	map_to_table(int fd, t_game *game)
{
	char *map;
	char *line;

	map = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin_free(map, line);
		xfree(line);
	}
	game->map_copy = ft_split(map, '\n');
	set_dimensions(game);
	xfree(map);
	close(fd);
}
