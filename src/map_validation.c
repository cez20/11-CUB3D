#include "../include/cub3d.h"

void	map_valid_extension(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (str == NULL || ft_strncmp(str, ".cub", 5) != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
}

// void	map_content_validation(int map_fd)
// {
// 	char	*map_line;

// 	map_line = get_next_line(map_fd);
// 	if (!map_line)
// 		error (ERR_EMPTY_MAP);
// }