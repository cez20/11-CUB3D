#include "../include/cub3d.h"


// If we mix tab and whitespaces, the different sizes breaks validation. To be checked.

void	game_parsing(t_game *game)
{
	verify_elements(game);
	verify_map_characters(game);
	verify_map_walls(game);
	replace_map_spaces(game);
}
