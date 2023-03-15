/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:29 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/15 10:59:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	keybinding(mlx_key_data_t input, void *tmp)
{
	t_game	*g;

	g = tmp;
	if (input.key == MLX_KEY_ESCAPE)
		mlx_close_window(g->mlx);
	if (input.key == MLX_KEY_RIGHT && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		look_right(g->rc);
	if (input.key == MLX_KEY_LEFT && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		look_left(g->rc);
	if (input.key == MLX_KEY_A && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		strafe(g->rc, 'L');
	if (input.key == MLX_KEY_D && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		strafe(g->rc, 'R');
	if (input.key == MLX_KEY_W && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		forward(g->rc);
	if (input.key == MLX_KEY_S && (input.action == MLX_PRESS
			|| input.action == MLX_REPEAT))
		backward(g->rc);
	raycaster(g);
}

int	cub3d(t_game *g)
{
	if (init_mlx_variables(g) != 0)
		errmsg("Error: MLX failed.\n", 1, g);
	init_dda_variables(g);
	load_and_convert_textures(g);
	raycaster(g);
	mlx_key_hook(g->mlx, &keybinding, g);
	mlx_loop(g->mlx);
	return (0);
}
