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
