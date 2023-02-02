#include "../include/cub3d.h"

static	int count_lines(int fd, t_game *game)
{
	int	i;
	char *line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		xfree(line);
		errmsg(ERR_EMPTY, 0, game);
	}
	while (line)
	{
		i++;
		xfree(line);
		line = get_next_line(fd);
	}
	return (i);
}

char	**map_to_table(char *mapfile, t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	char	**mapdata;
	int		mlen;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	mlen = count_lines(fd, game);
	mapdata = ft_xcalloc(sizeof(char *) * mlen + 1);
	if (!mapdata)
		return (NULL);
	mapdata[mlen] = NULL;
	line = get_next_line(fd);
	{
		mapdata[i] = ft_strdup(line);
		xfree (line);
		line = get_next_line(fd);
		i++;
	}
	mapdata[i - 1] = ft_strjoin_free(mapdata[i - 1], "\n");
	game->height = i;
	close(fd);
	return (mapdata);
}