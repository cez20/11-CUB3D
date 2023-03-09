#include "../include/cub3d.h"


// int	**fill_texture(xpm_t *tex)
// {
// 	int	**arr;
// 	int	i;
// 	int	j;

// 	arr = ft_calloc(sizeof(int *), tex->texture.height + 1);
// 	i = 3;
// 	while (++i < (int) tex->texture.height + 4)
// 	{
// 		j = 3;
// 		arr[i - 4] = ft_calloc(sizeof(int), tex->texture.width);
// 		while (++j < (int) tex->texture.width + 4)
// 			arr[i - 4][j - 4] = create_colour(
// 					tex->texture.pixels[(tex->texture.width * 4
// 						* (i - 4)) + (4 * (j - 4)) + 0],
// 					tex->texture.pixels[(tex->texture.width * 4
// 						* (i - 4)) + (4 * (j - 4)) + 1],
// 					tex->texture.pixels[(tex->texture.width * 4
// 						* (i - 4)) + (4 * (j - 4)) + 2],
// 					tex->texture.pixels[(tex->texture.width * 4
// 						* (i - 4)) + (4 * (j - 4)) + 3]);
// 	}
// 	return (arr);
// }


int	**create_2D_array_textures(xpm_t *image)
{
	int **tab;
	int i;
	int j;

	tab = ft_calloc(sizeof(int *), image->texture.height + 1);
	i = 3;
	while (++i < (int)image->texture.height + 4)
	{	
		j = 3;
		tab[i - 4] =  ft_calloc(sizeof(int), image->texture.width + 4);
		while (++j < (int) image->texture.width)
		{
			tab[i - 4][j - 4] = get_color(
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 0], 
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 1],
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 2], 
					image->texture.pixels[(image->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 3];
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

}