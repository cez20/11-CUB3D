#include "../include/cub3d.h"

void	init_variables(t_game *game)
{
	game->fd = 0;
	game->total_length = 0;
	game->map_index = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->nb_player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->game_copy = NULL;
	game->map_copy = NULL;
	game->elements_copy = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->tex = ft_calloc(1, sizeof(t_tex));
	game->rc = ft_calloc (1, sizeof(t_ray));
	game->tex->north = NULL;
	game->tex->south = NULL;
	game->tex->west = NULL;
	game->tex->east = NULL;
	game->tex->floor[0] = -1;
	game->tex->ceiling[0] = -1;
}

void	close_fds(t_game *game)
{
	close(game->fd);
}

/*static int	clean_exit (t_game *game)
{
	//check game->mlx, game->window
	free_table(game->map_copy);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_game	game;

	init_variables(&game);
	game_validation(&game, argc, argv[1]);
	game_sections_copy(&game, argv[1]);
	game_parsing(&game);
	free_game(&game);
	close_fds(&game);
//	return (clean_exit(&game));
	return (0);
}
