#include "../include/cub3d.h"

// void	flood_fill(int x, int y, t_game *game)
// {
// 	if (x < 0 || x > (game->height - 1) || y < 0 || y > (game->width - 1) || game->map_copy1[x][y] != '-')
// 		return ;
// 	flood_fill(x - 1, y, game);
// 	flood_fill(x, y + 1, game);
// 	flood_fill(x + 1, y, game);
// 	flood_fill(x, y - 1, game);
// 	flood_fill(x + 1, y + 1, game);
// 	flood_fill(x - 1, y + 1, game);
// 	flood_fill(x + 1, y - 1, game);
// 	flood_fill(x - 1, y - 1, game);
// }

// void	flood_fill(int x, int y, t_game *game)
// {
// 	if (game->map_copy1[x][y] == '1')
// 		return ;
// 	dfs(x, y, game);
// }
