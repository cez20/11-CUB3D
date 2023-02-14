#include "../include/cub3d.h"

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
