/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:58 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:38:59 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	errmsg(char *msg, int tofree, t_game *game)
{
	if (tofree == 1)
		free_game(game);
	write(2, msg, ft_strlen(msg));
	close(game->fd);
	exit(EXIT_FAILURE);
}
