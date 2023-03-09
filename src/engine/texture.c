#include "../include/cub3d.h"

void 	load_xpm42_textures(t_game *g)
{
	g->tex->no = mlx_load_xpm42("./img/north.xpm42");
	if (!g->tex->no)
		errmsg("Problem with loading xmp42 images", 1, g); // Je dois aussi free tout ce qui concerne mlx
	g->tex->so = mlx_load_xpm42("./img/south.xpm42");
	if (!g->tex->so)
		errmsg("Problem with loading xmp42 images", 1, g); // Je dois aussi free tout ce qui concerne mlx
	g->tex->we = mlx_load_xpm42("./img/west.xpm42");
	if (!g->tex->we)
		errmsg("Problem with loading xmp42 images", 1, g); // Je dois aussi free tout ce qui concerne mlx
	g->tex->ea = mlx_load_xpm42("./img/east.xpm42");
	if (!g->tex->ea)
		errmsg("Problem with loading xmp42 images", 1, g); // Je dois aussi free tout ce qui concerne mlx
	
}