#include "../include/cub3d.h"

//This function indicates player position: North, East, West, South (NEWS)
int	is_news(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

void	player_position(t_game *game, int x, int y)
{
	if (game->nb_player == 0)
	{
		game->player_x = x;
		game->player_y = y;
		game->nb_player++;
	}
	else
		game->nb_player++;
}

static void	skip_whitespaces(char **str)
{
	if (!*str || !**str)
		return ;
	while (**str && ft_isset(**str, WHITESPACE))
		*str += 1;
	return ;
}