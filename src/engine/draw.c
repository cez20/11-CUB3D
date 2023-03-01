#include "../include/cub3d.h"

//This function puts a colour in all the background of the image. When
// you move your player, it avoid that the colour of the player stays in
// the division. 
void draw_background(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (g->map_width * 64))
	{
		x = 0;
		while (x < (g->map_height * 64))
		{
			mlx_put_pixel(g->minimap, y, x , get_color(115, 147, 179, 155));
			x++;
		}
		y++;
	}
}

// This function draws a red square to represent the player. Given
// that X and Y represent here the position at the top left corner
// I advanced bpth the x and y of 25 to get close to the middle of
// each box.  
void	draw_player(t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 25;
	j = 25;
	mod_x = x + 25;
	mod_y = y + 25;
	while (i < 40)
	{
		while (j < 40)
		{
			mlx_put_pixel(g->minimap, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x + 25;
		j = 25;
		mod_y++;
		i++;
	}
}

// This function draws each elements of the map. All "1" which represents
// a wall, is painted in black and all empty area is in white.
void	draw_square(t_game *g, int x, int y, uint32_t color)
{
	int i;
	int j;
	int mod_x;
	int	mod_y;

	i = 1; // We start in one, so that the edge of each square in of a different colours
	j = 1;
	mod_x = x;
	mod_y = y;
	while (i < (64 - 1)) // We do minus 1 to make use that edge is of a different colour
	{
		while (j < (64 - 1))
		{
			mlx_put_pixel(g->minimap, mod_x, mod_y, color);
			j++;
			mod_x++;
		}
		mod_x = x;
		j = 1;
		mod_y++;
		i++;
	}
}

// This functions calls up the draw square function along with the color needed
// for each square. We inverted the x and y because when we want to circulate
// horizontally on the x_axis, we are in fact moving on the y-axis 
void draw_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == '1')
				draw_square (g, x * 64, y * 64, get_color(0, 0, 0, 255));
			else
				draw_square (g, x * 64, y * 64, get_color(255, 255, 255, 255));
			x++;
		}
		y++;
	}
}

u_int32_t	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
