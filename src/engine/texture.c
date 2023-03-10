#include "../include/cub3d.h"

void	texture_calculation(t_game *g)
{
	double	wall_x_hit; // It is the Y-value of the wall (even though it is x)
	double 	tex_width;

	// tex_num : get number associate with texture (Here always 1)
	// tex_width : get the exact texture width of the selected texture (here g->rc->no)
	g->tex->texture_num = g->rc->map[g->rc->map_y][g->rc->map_x];
	tex_width = (double)g->tex->no->texture.width;

	//wall_x_hit gives the exact "x" which is in reality the "y" coordinate of the wall texture that we have to use 
	//We round up the value to lower value to 
    if (g->rc->side == 0)
		wall_x_hit = g->rc->pos_y + g->rc->intersect_dist * g->rc->ray_dir_y; 
	else       
		wall_x_hit = g->rc->pos_x + g->rc->intersect_dist * g->rc->ray_dir_x;
	wall_x_hit -= floor((wall_x_hit)); 

	//texture gives the exact "x" coordinate on the texture we have to use  
	g->tex->texture_x = (int)(wall_x_hit * tex_width);

	if(g->rc->side == 0 && g->rc->ray_dir_x > 0)
		g->tex->texture_x = tex_width - g->tex->texture_x - 1;
	if(g->rc->side == 1 && g->rc->ray_dir_y < 0)
		g->tex->texture_x = tex_width - g->tex->texture_x - 1;
}

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
		tab[i - 4] =  ft_calloc(sizeof(int), image->texture.width); // je crois qu,on pourrait enlever le + 4
		while (++j < (int) image->texture.width + 4)
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

void 	load_textures(t_game *g)
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