/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:41 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:38:42 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_parsing(t_game *game)
{
	verify_elements(game);
	verify_map_characters(game);
	verify_map_walls(game);
	replace_map_spaces(game);
}

static void	game_valid_extension(t_game *game, char *str)
{
	str = ft_strrchr(str, '.');
	if (str == NULL || ft_strncmp(str, ".cub", 5) != 0)
	{
		close(game->fd);
		errmsg(ERR_EXT, 0, game);
	}
}

void	game_validation(t_game *game, int argc, char *argv)
{
	if (argc != 2)
		errmsg(ERR_ARGS, 0, game);
	game->fd = open(argv, O_DIRECTORY);
	if (game->fd > 0)
	{
		close(game->fd);
		errmsg(ERR_DIR, 0, game);
	}
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
		errmsg(ERR_FD, 0, game);
	game_valid_extension(game, argv);
}
