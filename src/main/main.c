#include "../include/cub3d.h"

void	init_variables(t_game *game)
{
	game->fd = 0;
	game->total_length = 0;
	game->map_index = 0;
	game->nb_player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->game_copy = NULL;
	game->map_copy = NULL;
	game->elements_copy = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

void	close_fds(t_game *game)
{
	close(game->fd);
}

static int	clean_exit (t_game *game)
{
	//check game->mlx, game->window
	free_table(game->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	init_variables(&game);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_NO_MAP);
	game_valid_extension(argv[1], game.fd);
	game_copy(&game, argv[1]);
	game_content_validation(&game);
	map_to_table(game.fd, &game);
	printf("[ MAP BEFORE FLOODFILL ]\n");
	print_map(game.map);
	flood_fill(11, 2, &game); // ints = starting player coordinates
	printf("\n[ MAP AFTER FLOODFILL ]\n");
	print_map(game.map);
	return (clean_exit(&game));
	free_game(&game);
	close_fds(&game);
	return (0);
}
