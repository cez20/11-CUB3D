#include "../include/cub3d.h"

//1- Circuler dans la map et trouver la ligne la plus longue 
//2- Calculer difference entre le plus long strlen et strlen de la ligne(cela va indique le nombre de tiret final a inserer)
//2- Malloc double pointeur
// 3- Si whitespace , remplacer par tiret
//4-  Si i = strlen

void	ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src || size == 0)
		return ;
	while (src[i])
	{
		if (src[i] == ' ')
			dst[i] = '-';
		else
			dst[i] = src[i];
		i++;
	}
	while (i < (size - 1))
		dst[i++] = '-';
	dst[i] = '\0';
}

int	find_width(t_game *game)
{
	int line;
	int width;
	int i;

	i = 0;
	width = 0;
	while (game->map_copy[i])
	{
		line = ft_strlen(game->map_copy[i]);
		if (line > width)
			width = line;
		i++;
	}
	return (width);
}

void	game_map_copy2(t_game *game)
{
	int i;
	//int length;
	
	i = 0;
	game->map_copy1 = ft_calloc(game->height + 1, sizeof(char *));
	while (i < game->height)
	{
		//length = 0;
		game->map_copy1[i] = ft_calloc(game->width + 1, sizeof(char));
		ft_strlcpy1(game->map_copy1[i], game->map_copy[i], game->width + 1);
		printf("%s\n", game->map_copy1[i]);
		i++;
	}

}

void	game_map_copy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->game_copy[i])
	{
		j = 0;
		while (ft_isset(game->game_copy[i][j], " "))
			j++;
		if (game->game_copy[i][j] == '1' || game->game_copy[i][j] == '0')
			break ;
		i++;
	}
	game->map_index = i;
	game->map_copy = &game->game_copy[i];
	game->height = game->total_length - game->map_index;
	game->width = find_width(game);
	printf("The largest width is %d\n", game->width);
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
	game_map_copy2(game); //Permet de faire une copie de la 2
	verify_map_extremities(game);
	verify_corners(game);
}
