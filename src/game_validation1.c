#include "../include/cub3d.h"

int	is_valid_character(char c)
{
	if (c == '1' | c == '0')
		return (1);
	else if (c == 'N'|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	game_map_content(t_game *game)
{
	char	**map;
	int 	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	map = game->map_copy;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(is_valid_character(map[i][j]) == 1) // Use ft_strchr instead? 
			{
				if (count > 1)
					error(ERR_CONTENT);
				if(map[i][j] == 'N'|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
					count++;
			}
			else
				error(ERR_CONTENT);
			j++;
		}
		i++;
	}
	if (count == 0)
		error(ERR_CONTENT);
}

void	game_content_validation(t_game *game)
{
	game_map_content(game);

}
