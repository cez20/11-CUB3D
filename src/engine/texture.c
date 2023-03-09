#include "../include/cub3d.h"


//This function createa a 2D array for textures based on width and height (64 X 64)
//This functions calls the fonction get_color and transform the RGBA value into an int.
// pixel[0] = R value, pixel[1] = G value, pixel[2] = 'B' value  pixel[3] = A value 
int	**create_2D_array_textures(xpm_t *image)
{
	int **tab;
	int i;
	int j;

	tab = ft_calloc(sizeof(int *), image->texture.height); // Maybe we should put height + 1 but not necessary 
	i = 3;
	while (++i < (int)image->texture.height + 4)
	{	
		j = 3;
		tab[i - 4] =  ft_calloc(sizeof(int), image->texture.width + 4); // je crois qu,on pourrait enlever le + 4
		while (++j < (int) image->texture.width)
		{
			tab[i - 4][j - 4] = get_color(
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 0], 
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 1],
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 2], 
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 3]);
		}
	}
	return (tab);
}

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
	g->tex->n = create_2D_array_textures(g->tex->no);
	g->tex->s = create_2D_array_textures(g->tex->so);
	g->tex->e = create_2D_array_textures(g->tex->ea);
	g->tex->w = create_2D_array_textures(g->tex->we);

}