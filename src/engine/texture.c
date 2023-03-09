#include "../include/cub3d.h"

//This function will create a 2D array, it will take every RGB colour of the texture 
// and transform it into an int
// void	create_2D_array_textures(xpm_t *image)
// {
// 	int **tab;

// 	tab = ft_calloc(sizeof(int *), image->texture.height)





// }

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
	//create_2D_array_textures(g->tex->no);

}